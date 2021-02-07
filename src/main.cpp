#include <iostream>
#include <string>

#include "utils.h"
#include "MvnVersion.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        error("Invalid arguments");
    }
    auto *v1 = new MvnVersion(std::string(argv[1]));
    auto *v2 = new MvnVersion(std::string(argv[2]));
    std::cout << ((*v1 == *v2) ? 0 : (*v1 > *v2) ? 1 : -1);
    return 0;
}
