#include <regex>

#include "MvnVersion.h"
#include "utils.h"

MvnVersion::MvnVersion(string version) {
    this->version = std::move(version);
    clean();
    split();
    create();
    convert();
}

std::ostream &operator<<(std::ostream &out, MvnVersion c) {
    out << c.version;
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

vector<string> MvnVersion::getTokens() {
    return this->tokens;
}

void MvnVersion::create() {
    vector<string> tmp;
    for (auto t: this->tokens) {
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

void MvnVersion::convert() {
    int i = 0;
}
