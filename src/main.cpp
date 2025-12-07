#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

#include "raylib.h"
#include "emulator/Emulator.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: chippp-8 FILE.ch8" << std::endl;
        return 1;
    }

    std::string filename{ argv[1] };
    std::ifstream f{};
    f.open(filename);

    unsigned char byte;
    std::vector<unsigned char> program;
    while (!f.eof()) {
        f >> std::noskipws >> byte;
        program.push_back(byte);
    }

    Emulator emulator{Environment{program}};
    emulator.execute();

    return 0;
}
