#ifndef MVN_COMPARE_CPP_UTILS_H
#define MVN_COMPARE_CPP_UTILS_H

#include <regex>
#include <string>
#include <iostream>

using namespace std;

static void error(const string &msg) {
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}

static bool isStrEmpty(const string &str) {
    return str.empty();
}

static vector<string> splitAlphaNum(string s) {
    const regex rx("(\\d+|\\D+)");
    const sregex_iterator last;
    vector<string> tokens;

    for (sregex_iterator i(s.begin(), s.end(), rx); i != last; ++i) {
        tokens.push_back((*i)[0]);
    }
    return tokens;
}

static string *getOrElse(vector<string> v, int i) {
    return i < v.size() ? new string(v.at(i)) : nullptr;
}

static bool isAlpha(string s) {
    return all_of(s.begin(), s.end(), ::isalpha);
}

static bool isNumeric(string s) {
    return all_of(s.begin(), s.end(), ::isdigit);
}

static bool isAlphaNumeric(string s) {
    return all_of(s.begin(), s.end(), ::isalnum);
}

#endif //MVN_COMPARE_CPP_UTILS_H
