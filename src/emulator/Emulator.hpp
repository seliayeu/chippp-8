#pragma once
#include "Environment.hpp"
#include <utility>

// TODO make PC incrementing more elegant
// doing it inside instructions feels weird
class Emulator {
    Environment env;
public:
    Emulator(Environment&& env) : env{ std::move(env) }{};
    void execute();
};
