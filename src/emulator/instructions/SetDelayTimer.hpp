#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class SetDelayTimer : public Instruction {
public:
    Register reg{};

    SetDelayTimer(Register reg) : reg{ reg } {};
    void op(Environment& env) override {
        env.timerRegister = env.VRegisters[static_cast<unsigned int>(reg)];
        env.pc += 2;
    }
};
