#ifndef MVN_COMPARE_CPP_MVNVERSION_H
#define MVN_COMPARE_CPP_MVNVERSION_H

#include <string>
#include <vector>

using namespace std;

class MvnVersion {
    string version;
    int majorVersion = 0;
    int minorVersion = 0;
    int patchVersion = 0;
    int qualifierPrefix = 0;
    int qualifierType = 0;
    int qualifierSuffix = 0;

    vector<vector<string>> allQualifiers{
            {"alpha",     "a"},
            {"beta",      "b"},
            {"milestone", "m"},
            {"rc",        "cr"},
            {"snapshot"},
            {"",          "ga", "final"},
            {"sp"}
    };

public:
    explicit MvnVersion(string version);

    friend ostream &operator<<(ostream &out, MvnVersion mvnVersion);
};


#endif //MVN_COMPARE_CPP_MVNVERSION_H
