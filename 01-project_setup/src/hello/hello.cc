#include <iostream> 

#include <hello/hello.h>

using namespace hello;

void greet(std::string const& name) {
    std::cout << "Hello " << name << "\n";
}