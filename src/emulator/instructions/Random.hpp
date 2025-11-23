#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"
#include <random>

class Random : public Instruction {
public:
    const unsigned char byte{};
    Register dest;
    unsigned int raw;
    Random(unsigned char byte, Register dest, unsigned int raw) : byte{ byte }, dest{ dest }, raw{ raw } {};
    void op(Environment& env) override {
        unsigned int destInd{ static_cast<unsigned int>(dest) };
        env.VRegisters[destInd] = env.dist(env.gen) & byte;
        env.pc += 1;
    }
};
