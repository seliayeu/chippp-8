#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class SkipNotPressed : public Instruction {
public:
    unsigned int raw;
    Register reg;

    SkipNotPressed(unsigned int raw, Register reg) : raw{ raw }, reg{ reg } {};
    void op(Environment& env) override {
        // TODO
        env.pc += 1;
    }
};
