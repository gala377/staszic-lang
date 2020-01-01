#ifndef PARSER_AST_HPP_
#define PARSER_AST_HPP_

#include <memory>
#include <parser/nodes.hpp>

namespace ast {
    class AST {
    public:
        AST(std::unique_ptr<Program> root);

        const std::unique_ptr<Program>& root() const;
    private:
        std::unique_ptr<Program> root_;
    };
}


#endif