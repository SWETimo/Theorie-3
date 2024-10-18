#include <fmt/chrono.h>
#include <fmt/format.h>
#include <vector>
#include <random> // Für den Zufallsgenerator
#include <algorithm>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    int counter = 20;

    try
    {
        app.add_option("-c, --count", counter, "Zählervariable");
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());
    fmt::print("Counter value: {}\n", counter);

    
    /* INSERT YOUR CODE HERE */
     fmt::print("Hello, {}!\n", app.get_name());
    fmt::print("Counter value: {}\n", counter); // Verwende den richtigen Formatstring für int

    // Erstellen eines Vektors mit der Größe von 'counter' und füllen mit Zufallszahlen
    std::vector<int> values(counter); // Korrekte Vektordeklaration
    std::random_device rd;   // Zufallsquelle
    std::mt19937 gen(rd());  // Mersenne-Twister Zufallszahlengenerator
    std::uniform_int_distribution<> distrib(1, 100); // Zufallswerte von 1 bis 100

    // Vektor mit zufälligen Werten füllen
    for (int &value : values) {
        value = distrib(gen);
    }

    fmt::print("Random values:\n");
    for (const int &value : values) {
        fmt::print("{} ", value);
    }
    fmt::print("\n");

    auto start = std::chrono::system_clock::now();
    std::sort(values.begin(), values.end());
    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);

    // Die Werte des Vektors ausgeben
    fmt::print("Random values:\n");
    for (const int &value : values) {
        fmt::print("{} ", value);
    }

    fmt::print("\n");

    fmt::print("Die benötigte Zeit beträgt: {}", elapsed.count());

    fmt::print("\n");

    return 0; /* exit gracefully*/
}
