#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class And : public Instruction {
public:
    unsigned int raw;
    const Register dest{};
    const Register source{};
    unsigned char nibble;
    And(unsigned int raw, Register dest, Register source, unsigned char nibble) : raw{ raw }, dest{ dest }, source{ source }, nibble{ nibble } {};
    void op(Environment& env) override {
        // TODO
        env.pc += 1;
    }
};
