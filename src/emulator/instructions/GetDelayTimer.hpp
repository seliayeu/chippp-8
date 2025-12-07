#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class GetDelayTimer : public Instruction {
public:
    Register reg{};
    GetDelayTimer(Register reg) : reg{ reg } {};
    void op(Environment& env) override {
        env.VRegisters[static_cast<unsigned int>(reg)] = env.timerRegister;
        env.pc += 2;
    }
};
