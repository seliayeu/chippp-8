#pragma once
#include <array>
#include <memory>

class Instruction;

struct Environment
{
    std::array<unsigned char, 17> registers{}; // 0 to 15: VX, 16: I
    unsigned int basePc{ 0x200 };
    unsigned int pc{ 0x200 };
    std::array<std::shared_ptr<Instruction>, 592> memory; // 0x200 to 0x69F (inclusive) is 1184 bytes divided by 2
};
