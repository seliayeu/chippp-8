#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class StoreRegisters : public Instruction {
public:
    unsigned int raw;
    const Register reg{};
    StoreRegisters(unsigned int raw, Register reg) : raw{ raw }, reg{ reg } {};
    void op(Environment& env) override {
        unsigned char val{ env.VRegisters[static_cast<unsigned int>(reg)] };
        env.memory[env.IRegister] = val / 100;
        val %= 100;
        env.memory[env.IRegister + 1] = val / 10;
        val %= 10;
        env.memory[env.IRegister + 2] = val;
        env.pc += 1;
    }
};
