#ifndef REPL_HPP_
#define REPL_HPP_

#include <string>

class REPL {
public:
    void run();

protected:
    static const std::string PROMPT;
    static const std::string CLOSE_COMMAND;

    void print_prompt();
    std::string get_line();

};

#endif