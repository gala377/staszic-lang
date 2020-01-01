#include <iostream>
#include <string>

#include <repl.hpp>

using namespace std::string_literals;

int main() {
    std::cout << "Starting staszic-lang REPL\n";
    REPL().run();
    std::cout << "Quitting REPL\n";
    return 0;
}