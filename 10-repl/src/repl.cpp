#include <iostream>
#include <stdexcept>
#include <string>

#include <repl.hpp>
#include <source/string.hpp>
#include <lexer/lexer.hpp>
#include <parser/parser.hpp>
#include <visitor/eval.hpp>

const std::string REPL::PROMPT = "> ";
const std::string REPL::CLOSE_COMMAND = "quit";

void REPL::run() {
    for(
        auto input = (print_prompt(), get_line());
        input != CLOSE_COMMAND; 
        input = (print_prompt(), get_line())
    ) {
        try {
            source::String s{input};
            lexer::Lexer l{s};
            parser::Parser p{l};
            auto ast = p.parse();
            visitor::Eval e{};
            e.visit(*ast.root());
            if(auto res = e.result(); res) {
                std::cout <<  *res << "\n";
            } else {
                std::cout << "Could not evaluate expression\n";
            }
        } catch(std::runtime_error& e) {
            std::cout << "Error: " <<  e.what() << "\n";
        }
    }
}

std::string REPL::get_line() {
    std::string buff;
    std::getline(std::cin, buff);
    return buff;
}

void REPL::print_prompt() {
    std::cout << PROMPT;
}