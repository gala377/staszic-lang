#include <visitor/eval.hpp>

std::optional<int> visitor::Eval::result() const {
    return res_;
}

void visitor::Eval::visit(ast::Node& n) {
    throw std::runtime_error("Cannot visit an abstract node");
}

void visitor::Eval::visit(ast::Program& n) {
    for(auto& n: n.nodes) {
        n->accept(*this);
    }
}

void visitor::Eval::visit(ast::Expr& n) {
    throw std::runtime_error("Cannot visit an abstract node");
}

void visitor::Eval::visit(ast::BinaryExpr& n) {
    throw std::runtime_error("Cannot visit an abstract node");
}

void visitor::Eval::visit(ast::UnaryExpr& n) {
    throw std::runtime_error("Cannot visit an abstract node");
}

void visitor::Eval::visit(ast::AddExpr& n) {
    n.lhs_->accept(*this);
    auto lhs = res_.value();
    n.rhs_->accept(*this);
    auto rhs = res_.value();
    res_ = {rhs + lhs};
}

void visitor::Eval::visit(ast::MultExpr& n) {
    n.lhs_->accept(*this);
    auto lhs = res_.value();
    n.rhs_->accept(*this);
    auto rhs = res_.value();
    res_ = {rhs * lhs};
}

void visitor::Eval::visit(ast::NegExpr& n) {
    n.expr_->accept(*this);
    auto expr = res_.value();
    res_ = {-expr};
}

void visitor::Eval::visit(ast::ParenExpr& n) {
    n.expr_->accept(*this);
}

void visitor::Eval::visit(ast::Int& n) {
    res_ = {n.v_};
}