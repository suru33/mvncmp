#include <iostream>
#include <string>

#include "utils.h"

using namespace std;

int main(int argc, char *argv[]) {

    string v1 = "1.0milestone-1";
    string v2 = "1.0.0-a1";

    cout << "Hello, World!" << endl;

    vector<string> tokens = splitAlphaNum(v1);
    string val = getOrElse(tokens, 100);

    return 0;
}
