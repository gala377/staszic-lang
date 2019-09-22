#include <iostream>

#include <hello/hello.h>


void hello::greet(std::string const& name) {
    std::cout << make_greeting(name) << "\n";
}

std::string hello::make_greeting(const std::string &name) {
    using namespace std::string_literals;
    return "Hello "s + name;
}