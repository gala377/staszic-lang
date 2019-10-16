#include <iostream> 

#include <hello/hello.h>

void hello::greet(const std::string& name) {
    std::cout << "Hello " << name << "\n";
}