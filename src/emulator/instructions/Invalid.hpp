#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class Invalid : public Instruction { // not a valid opcode: pure data
public:
    unsigned int raw;
    Invalid(unsigned int raw) : raw{ raw } {}
    void op(Environment&) override {}
};
