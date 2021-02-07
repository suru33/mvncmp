#ifndef MVN_COMPARE_CPP_UTILS_H
#define MVN_COMPARE_CPP_UTILS_H

#include <regex>
#include <string>
#include <iostream>

using namespace std;

void error(string msg) {
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}

bool isStrEmpty(const string &str) {
    return str.empty();
}

vector<string> splitAlphaNum(string s) {
    const regex rx("(\\d+|\\D+)");
    const sregex_iterator last;
    vector<string> tokens;

    for (sregex_iterator i(s.begin(), s.end(), rx); i != last; ++i) {
        tokens.push_back((*i)[0]);
    }
    return tokens;
}

string *getOrElse(vector<string> v, int i) {
    return i < v.size() ? new string(v.at(i)) : nullptr;
}

#endif //MVN_COMPARE_CPP_UTILS_H
