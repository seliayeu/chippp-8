#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"
#include <limits.h>

class AddIRegister : public Instruction {
public:
    const Register reg{};
    AddIRegister(Register reg) : reg{ reg } {};

    void op(Environment& env) override {
        env.IRegister += env.VRegisters[static_cast<unsigned int>(reg)];
        env.pc += 2;
    }
};
