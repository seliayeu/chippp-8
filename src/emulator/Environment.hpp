#pragma once
#include <array>
#include <bitset>
#include <random>
#include <cstddef>
#include <vector>

struct Environment {
    std::array<unsigned char, 16> VRegisters{};
    unsigned int IRegister;
    unsigned int FRegister;
    unsigned char soundRegister{ 0 };
    unsigned char timerRegister{ 0 };

    unsigned int basePc{ 0x200 };
    unsigned int pc{ basePc };
    unsigned int end{};
    unsigned char sp{ 0 };
    std::array<unsigned int, 16> stack{};
    std::array<unsigned char, 4096> memory{};
    std::array<std::bitset<64>, 32> display{};

    bool timerReady{ false };
    bool soundReady{ false };

    std::array<unsigned int, 15> spriteInds{};

    std::mt19937 gen{};
    std::uniform_int_distribution<std::mt19937::result_type> dist{std::uniform_int_distribution<std::mt19937::result_type>(0, 0xFF)};

    Environment(std::vector<unsigned char>& program);
    void clearDisplay();
};
