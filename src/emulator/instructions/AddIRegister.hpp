#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"
#include <limits.h>

class AddIRegister : public Instruction {
public:
    unsigned int raw;
    const Register reg{};
    AddIRegister(unsigned int raw, Register reg) : raw{ raw }, reg{ reg } {};

    void op(Environment& env) override {
        env.IRegister += env.VRegisters[static_cast<unsigned int>(reg)];
        env.pc += 1;
    }
};
