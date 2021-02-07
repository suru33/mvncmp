#ifndef MVN_COMPARE_CPP_MVNVERSION_H
#define MVN_COMPARE_CPP_MVNVERSION_H

#include <string>
#include <vector>

using namespace std;

class MvnVersion {
    const vector<vector<string>> allQualifiers{
            {"alpha",     "a"},
            {"beta",      "b"},
            {"milestone", "m"},
            {"rc",        "cr"},
            {"snapshot"},
            {"",          "ga", "final"},
            {"sp"}
    };

    string version;
    vector<string> tokens;

    int majorVersion = 0;
    int minorVersion = 0;
    int patchVersion = 0;
    int qualifierPrefix = 0;
    int qualifierType = 0;
    int qualifierSuffix = 0;
    int finalVersion = 0;

    static void checkAndForward(vector<string> *tokens, int *index, int *target, int defaultValue);

    void clean();

    void split();

    void create();

    void convert();

public:
    explicit MvnVersion(string version);

    bool operator==(MvnVersion const &other) const;

    bool operator>(MvnVersion const &other) const;

    bool operator<(MvnVersion const &other) const;

    friend ostream &operator<<(ostream &out, const MvnVersion &mvnVersion);
};

#endif //MVN_COMPARE_CPP_MVNVERSION_H
