#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class JumpRegister : public Instruction {
public:
    unsigned int raw;
    const Register dest{};
    unsigned int addr;
    JumpRegister(unsigned int raw, unsigned int addr) : raw{ raw }, addr{ addr } {};
    void op(Environment& env) override {
        env.pc = addr + env.VRegisters[0];
    }
};
