#include <fmt/chrono.h>
#include <fmt/format.h>

#include "vectorint.hpp"

auto main(int argc, char **argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, World!\n");

    VectorInt data(20);
    data.print();

    // resize the vector to 10 elements
    auto resize_value = 10;
    auto prev_size = data.size();
    fmt::print("Perform a resize from {} to {}\n",prev_size,resize_value);
    data.resize(resize_value);
    if(resize_value != data.size()) {
        fmt::print("A size mismatch detected expected value {} actual value {}\n",resize_value,data.size());
        return 1;
    }
    fmt::print("Performed a resize from {} to {}\n",prev_size,resize_value);
    
    resize_value = 42;
    prev_size = data.size();
    fmt::print("Perform a resize from {} to {}\n",prev_size,resize_value);
    prev_size = data.size();
    data.resize(resize_value);
    if(resize_value != data.size()) {
        fmt::print("A size mismatch detected expected value {} actual value {}\n",resize_value,data.size());
        return 1;
    }
    fmt::print("Performed a resize from {} to {}\n",prev_size,resize_value);

    // Testing the at method
    fmt::print("Testing the at method by inserting elements ");
    const auto value_to_insert = 4711;
    for (int i = 0; i < data.size(); i++)
    {
        int& value = data.at(i);
        value = value_to_insert;
        if (value_to_insert != data.at(i))
        {
            fmt::print("[failure]\n");
            fmt::print("Value missmatch! Expected {} received {}\n", value_to_insert, data.at(i));
            return 1;
        }
    }
    fmt::print("[success]\n");
    data.print();
    // resize and check values
    fmt::print("Testing the at method by resizing after add ");
    auto expected_value = value_to_insert;
    data.resize(10);
    for (int i = 0; i < data.size(); i++)
    {
        if (expected_value != data.at(i))
        {
            fmt::print("[failure]\n");
            fmt::print("Value missmatch! Expected {} received {} at {}\n", expected_value, data.at(i),i);
            return 1;
        }
    }
    fmt::print("[success]\n");
    return 0; /* exit gracefully*/
}