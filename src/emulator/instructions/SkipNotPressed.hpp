#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class SkipNotPressed : public Instruction {
public:
    Register reg;

    SkipNotPressed(Register reg) : reg{ reg } {};
    void op(Environment& env) override {
        if (!env.checkPressed(env.VRegisters[static_cast<unsigned char>(reg)]))
            env.pc += 4;
        else
            env.pc += 2;
    }
};
