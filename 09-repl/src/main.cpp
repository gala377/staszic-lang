#include <iostream>
#include <string>

#include <source/string.hpp>
#include <lexer/lexer.hpp>
#include <parser/parser.hpp>
#include <visitor/eval.hpp>

using namespace std::string_literals;

int main() {
    source::String s{"( 2 + 2 ) * 2"s};
    lexer::Lexer l{s};
    parser::Parser p{l};
    visitor::Eval e{};
    auto ast = p.parse();
    e.visit(*ast.root());
    if(auto res = e.result(); res) {
        std::cout << "Evaluated tes to: " << *res << "\n";
    } else {
        std::cout << "Could not evaluate expression\n";
    }
    return 0;
}