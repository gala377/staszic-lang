#include <parser/nodes.hpp>

ast::Program::Program(std::vector<std::unique_ptr<Node>> nodes):
    nodes(std::move(nodes)) {}

void ast::Program::add_node(std::unique_ptr<Node> node) {
    nodes.emplace_back(std::move(node));
}

void ast::Program::accept(ast::Visitor &v) {
    v.visit(*this);
}

void ast::BinaryExpr::accept(ast::Visitor &v) {
    v.visit(*this);
}

void ast::UnaryExpr::accept(ast::Visitor &v) {
    v.visit(*this);
}

void ast::AddExpr::accept(ast::Visitor &v) {
    v.visit(*this);
}

void ast::MultExpr::accept(ast::Visitor &v) {
    v.visit(*this);
}

void ast::NegExpr::accept(ast::Visitor &v) {
    v.visit(*this);
}

void ast::ParenExpr::accept(ast::Visitor &v) {
    v.visit(*this);
}

void ast::Int::accept(ast::Visitor &v) {
    v.visit(*this);
}
