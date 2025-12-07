#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"
#include <random>

class Random : public Instruction {
public:
    Register dest;
    const unsigned char byte{};
    Random(Register dest, unsigned char byte) : dest{ dest }, byte{ byte } {};
    void op(Environment& env) override {
        unsigned int destInd{ static_cast<unsigned int>(dest) };
        env.VRegisters[destInd] = env.dist(env.gen) & byte;
        env.pc += 2;
    }
};
