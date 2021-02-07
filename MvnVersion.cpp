#include <regex>
#include <sstream>

#include "MvnVersion.h"
#include "utils.h"

MvnVersion::MvnVersion(string version) {
    this->version = std::move(version);
    clean();
    split();
    create();
    convert();
}

std::ostream &operator<<(std::ostream &out, const MvnVersion &mvnVersion) {
    out << "MvnVersion<" << mvnVersion.version
        << ", (" << mvnVersion.majorVersion
        << ", " << mvnVersion.minorVersion
        << ", " << mvnVersion.patchVersion
        << ", " << mvnVersion.qualifierPrefix
        << ", " << mvnVersion.qualifierType
        << ", " << mvnVersion.qualifierSuffix << ")>";
    return out;
}

void MvnVersion::clean() {
    auto it = remove_if(this->version.begin(), this->version.end(), ::isspace);
    this->version.erase(it, this->version.end());
    transform(this->version.begin(), this->version.end(), this->version.begin(), ::tolower);
}

void MvnVersion::split() {
    const regex r("\\.|\\-");
    const sregex_token_iterator first(this->version.begin(), this->version.end(), r, -1);
    const sregex_token_iterator last;

    this->tokens = {first, last};
    auto it = remove_if(tokens.begin(), tokens.end(), &isStrEmpty);
    tokens.erase(it, tokens.end());
}

void MvnVersion::create() {
    vector<string> tmp;
    for (const auto &t: this->tokens) {
        if (isNumeric(t)) {
            tmp.push_back(t);
        } else if (isAlphaNumeric(t)) {
            vector<string> an = splitAlphaNum(t);
            tmp.insert(tmp.end(), an.begin(), an.end());
        } else {
            error("Invalid version name: " + this->version);
        }
    }
    this->tokens = std::move(tmp);
}

void MvnVersion::checkAndForward(vector<string> *tokens, int *index, int *target, int defaultValue = 0) {
    string *temp = getOrElse(*tokens, *index);
    if (temp != nullptr && isNumeric(*temp)) {
        std::stringstream ss(*temp);
        ss >> *target;
        ++*index;
    } else {
        *target = defaultValue;
    }
}

void MvnVersion::convert() {
    int i = 0;

    MvnVersion::checkAndForward(&tokens, &i, &majorVersion);
    MvnVersion::checkAndForward(&tokens, &i, &minorVersion);
    MvnVersion::checkAndForward(&tokens, &i, &patchVersion);

    if (i < tokens.size()) {
        vector<string> qualifier = {tokens.begin() + i, tokens.end()};
        string qualifierStr;
        for (auto const &s : qualifier) qualifierStr += s;
        qualifier = std::move(splitAlphaNum(qualifierStr));
        i = 0;
        MvnVersion::checkAndForward(&qualifier, &i, &qualifierPrefix);

        string *qualifierTypeName = getOrElse(qualifier, i);
        if (qualifierTypeName != nullptr && isAlpha(*qualifierTypeName)) {
            ++i;
            bool found = false;
            for (int j = 0; j < allQualifiers.size(); ++j) {
                vector<string> subVector = allQualifiers[j];
                if (std::find(subVector.begin(), subVector.end(), *qualifierTypeName) != subVector.end()) {
                    this->qualifierType = j;
                    found = true;
                    break;
                }
            }
            if (!found) {
                error("Invalid qualifier found in: " + version);
            }
        } else {
            this->qualifierType = 5;
        }
        MvnVersion::checkAndForward(&qualifier, &i, &qualifierSuffix);
    } else {
        qualifierPrefix = 0;
        qualifierType = 5;
        qualifierSuffix = 0;
    }
    finalVersion = 100000 * majorVersion
                   + 10000 * minorVersion
                   + 1000 * patchVersion
                   + 100 * qualifierPrefix
                   + 10 * qualifierType
                   + qualifierSuffix;
}

bool MvnVersion::operator==(const MvnVersion &other) const {
    return finalVersion == other.finalVersion;
}

bool MvnVersion::operator>(const MvnVersion &other) const {
    return finalVersion > other.finalVersion;
}

bool MvnVersion::operator<(const MvnVersion &other) const {
    return finalVersion < other.finalVersion;
}
