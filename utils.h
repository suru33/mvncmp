#ifndef MVN_COMPARE_CPP_UTILS_H
#define MVN_COMPARE_CPP_UTILS_H

#include <regex>

using namespace std;

void error(string s) {
    cerr << s << endl;
    exit(EXIT_FAILURE);
}

vector<string> splitAlphaNum(string s) {
    const sregex_iterator end;
    vector<string> tokens;
    regex basicRegex("(\\d+|\\D+)");

    for (sregex_iterator i(s.begin(), s.end(), basicRegex); i != end; ++i) {
        cout << (*i)[0] << endl;
        tokens.push_back((*i)[0]);
    }
    return tokens;
}

string getOrElse(vector<string> v, int i) {
    try {
        return v.at(i);
    } catch (...) {
        return nullptr;
    }
}

#endif //MVN_COMPARE_CPP_UTILS_H
