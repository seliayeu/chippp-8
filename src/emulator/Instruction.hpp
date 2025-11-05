#pragma once
#include "Environment.hpp"

class Instruction
{
public:
    const unsigned int raw{};
    virtual void op(Environment& env) = 0;
    virtual ~Instruction() = 0;
};
