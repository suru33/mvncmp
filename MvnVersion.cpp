#include <iostream>
#include "MvnVersion.h"

using namespace std;

MvnVersion::MvnVersion(string version) {
    this->version = version;
    cout << this->allQualifiers[0][0] << endl;
}

std::ostream &operator<<(ostream &out, MvnVersion c) {
    out << c.version;
    return out;
}
