#pragma once
#include "Environment.hpp"
#include "Instruction.hpp"
#include <utility>
#include <memory>

// TODO make PC incrementing more elegant
// doing it inside instructions feels weird
class Emulator {
    Environment env;
public:
    Emulator(Environment&& env) : env{ std::move(env) }{};
    void execute();
    void executeInstruction(std::unique_ptr<Instruction> instr);
};
