#pragma once
#include <array>
#include <memory>
#include <bitset>
#include <random>

class Instruction;

struct Environment {
    std::array<unsigned char, 16> VRegisters{};
    unsigned int IRegister;
    unsigned int basePc{ 0x200 };
    unsigned int pc{ 0x200 };
    unsigned char sp{ 0 };
    std::array<unsigned int, 16> stack{};
    std::array<std::shared_ptr<Instruction>, 592> memory; // 0x200 to 0x69F (inclusive) is 1184 bytes divided by 2
    std::array<std::bitset<64>, 32> display{};

    std::mt19937 gen{};
    std::uniform_int_distribution<std::mt19937::result_type> dist{std::uniform_int_distribution<std::mt19937::result_type>(0, 0xFF)};

    Environment() {
        std::random_device rd;
        gen = std::mt19937(rd());
    }

    void clearDisplay() {
        for (auto& row : display)
            row.reset();
    }
};
