#include <fmt/chrono.h>
#include <fmt/format.h>

#include <iostream>
#include <random>

#include "CLI/CLI.hpp"
#include "config.h"

int foo;
int foo2;
int data =4711;

const int rodata = 42;

auto main(int argc, char **argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     */
    fmt::print("Value of variable foo {} address of variable foo{}\n"),
    foo,
    fmt::ptr(&foo);
    
     fmt::print("Value of variable data {} address of variable data{}\n"),
    data,
    fmt::ptr(&data);

     fmt::print("Value of variable rodata {} address of variable rodata{}\n"),
    rodata,
    fmt::ptr(&rodata);
    return 0; /* exit gracefully*/

}
