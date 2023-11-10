#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */

    int count =20;
    std::srand(std::time(0));
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, "Variable");
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
    std::vector<int> data(count);
    std::srand(std::time(0));
    std::generate(data.begin(), data.end(), []() { return std::rand() % 100 + 1; });

       /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */

    fmt::print("Generated vector: ");
    for (const auto &value : data)
    {
        fmt::print("{} ", value);
    }
    fmt::print("\n");

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
