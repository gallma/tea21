#include <fmt/chrono.h>
#include <fmt/format.h>
#include <vector>
#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    auto count = 20;

    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, "Variable count als Integer");
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
    std::vector<int> data(count);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < count; i++) 
    {
        data[i] = rand()%100 +1;
        

    }
    fmt::print("\n");

    auto start = std::chrono::system_clock::now();
    std::sort(data.begin(), data.end());

     auto end = std::chrono::system_clock::now();
    auto elapsed = end - start;
    printf("Sort vector: \n");
    for(int i = 0; i < count; i++)
    {
        fmt::print("{} ", data[i]);
    }

    fmt::print("\nTime for sorting:\n{}",elapsed);

    return 0;
    
}