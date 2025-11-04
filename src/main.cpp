#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: chippp-8 FILE.ch8" << std::endl;
        return 1;
    }

    std::string filename{ argv[1] };
    std::ifstream f{};
    f.open(filename);

    unsigned char byte;
    int count{ 0 };
    while (!f.eof()) {
        f >> std::noskipws >> byte;
        std::cout << std::setfill('0') << std::setw(2) << std::hex << static_cast<int>(byte);
        if (++count % 2 == 0)
            std::cout << std::endl;
    }

    return 0;
}
