#include <iostream>

#include <hello/hello.h>


void hello::greet(std::string const& name) {
    std::cout << make_greeting(name) << "\n";
}

std::string hello::make_greeting(const std::string &name) {
    using namespace std::string_literals;
    if (name.empty()) {
        return hello::EMPTY_NAME_MSG;
    }
    return "Hello "s + name;
}