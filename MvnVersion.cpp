#include "MvnVersion.h"
#include <regex>

#include "utils.h"

MvnVersion::MvnVersion(string version) {
    this->version = std::move(version);
    clean();
    split();
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
