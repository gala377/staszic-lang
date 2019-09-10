#include <iostream> 

#include <hello/hello.h>

void hello::greet(std::string const& name) {
    std::cout << "Hello " << name << "\n";
}