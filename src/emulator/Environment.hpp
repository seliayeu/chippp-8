#pragma once
#include <array>
#include <bitset>
#include <random>

struct Environment {
    std::array<unsigned char, 16> VRegisters{};
    unsigned int IRegister;
    unsigned int basePc{ 0x200 };
    unsigned int pc{ 0x200 };
    unsigned char sp{ 0 };
    std::array<unsigned int, 16> stack{};
    std::array<unsigned char, 4096> memory;
    std::array<std::bitset<64>, 32> display{};

    std::array<unsigned int, 15> spriteInds{};

    std::mt19937 gen{};
    std::uniform_int_distribution<std::mt19937::result_type> dist{std::uniform_int_distribution<std::mt19937::result_type>(0, 0xFF)};

    Environment();
    void clearDisplay();
};
