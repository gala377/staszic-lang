#include <parser/ast.hpp>

ast::AST::AST(std::unique_ptr<ast::Program> root): root_(std::move(root)) {}

const std::unique_ptr<ast::Program>& ast::AST::root() const {
    return root_;
}