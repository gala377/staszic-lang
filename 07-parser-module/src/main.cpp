#include <iostream>
#include <string>

#include <source/string.hpp>
#include <lexer/lexer.hpp>
#include <parser/parser.hpp>

using namespace std::string_literals;

int main() {
    source::String s{"2 + 2 * 2 + ( - 1 )"s};
    lexer::Lexer l{s};
    parser::Parser p{l};
    auto ast = p.parse();
    return 0;
}