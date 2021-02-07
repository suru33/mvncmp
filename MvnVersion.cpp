#include "MvnVersion.h"

MvnVersion::MvnVersion(string version) {
    this->version = std::move(version);
}

std::ostream &operator<<(std::ostream &out, MvnVersion c) {
    out << c.version;
    return out;
}
