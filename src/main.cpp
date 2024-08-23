#include <iostream>
#include "ArgumentParser/ArgumentParser.h"

int main(int argc, char *argv[]) {
    ArgumentParser parser(argc, argv);
    std::cout << parser.getAllAsString() << std::endl;

    return 0;
}
