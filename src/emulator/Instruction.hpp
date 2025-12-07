#pragma once
#include "Environment.hpp"

class Instruction {
public:
    virtual void op(Environment& env) = 0;
    virtual ~Instruction() = default;
};
