#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class Jump : public Instruction {
public:
    unsigned int raw;
    unsigned int addr;
    Jump(unsigned int raw, unsigned int addr) : raw{ raw }, addr{ addr } {};
    void op(Environment& env) override {
        env.pc = addr;
    }
};
