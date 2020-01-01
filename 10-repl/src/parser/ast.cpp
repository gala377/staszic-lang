#include <parser/ast.hpp>

ast::AST::AST(std::unique_ptr<ast::Program> root): root_(std::move(root)) {}

std::unique_ptr<ast::Program>& ast::AST::root() {
    return root_;
}

const std::unique_ptr<ast::Program>& ast::AST::root() const {
    return root_;
}