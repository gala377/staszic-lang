#include <iostream> 

#include <hello/hello.hpp>

void hello::greet(std::string const& name) {
    std::cout << "Hello " << name << "\n";
}