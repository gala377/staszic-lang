#include <iostream> 

#include <hello/hello.hpp>

void hello::greet(const std::string& name) {
    std::cout << "Hello " << name << "\n";
}