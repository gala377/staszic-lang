#include <iostream>
#include <string>

#include <source/string.hpp>

using namespace std::string_literals;

int main() {
    source::String s{"Hello"s};
    std::cout << "First character " << s.curr() << '\n';
    s.bump();
    std::cout << "Bump and second char: " << s.curr() << '\n';
    std::cout << "And peek: " << s.peek() << '\n';
    s.bump();
    s.bump();
    s.bump();
    s.bump();
    s.bump();
    s.bump();
    s.bump();
    std::cout << "Bumping past end: " << s.curr() << '\n';
    std::cout << "And peek: " << s.peek() << '\n';
    return 0;
}