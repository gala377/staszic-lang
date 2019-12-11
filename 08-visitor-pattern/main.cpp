#include <iostream>
#include <memory>
#include <stdexcept>

#include "nodes.hpp"
#include "visitor.hpp"

using namespace nodes;

class PrintVisitor: public Visitor {
public: 
    void visit(Expr& n) override {
        throw std::runtime_error("Cannot visit abstract type");   
    }
    void visit(BinaryExpr& n) override {
        throw std::runtime_error("Cannot visit abstract type");
    }
    void visit(UnaryExpr& n) override {
        throw std::runtime_error("Cannot visit abstract type");
    }
    void visit(AddExpr& n) override {
        n.lhs_->accept(*this);
        std:: cout << " + ";
        n.rhs_->accept(*this);
    }
    void visit(MultExpr& n) override {
        n.lhs_->accept(*this);
        std:: cout << " * ";
        n.rhs_->accept(*this);
    }
    void visit(NegExpr& n) override {
        std:: cout << "-";
        n.expr_->accept(*this);
    }
    void visit(ParenExpr& n) override {
        std:: cout << "(";
        n.expr_->accept(*this);
        std::cout << ")";
    }
    void visit(Int& n) override {
        std::cout << n.v_;
    }

};

int main() {
    auto tree = 
        std::make_unique<AddExpr>(
            std::make_unique<NegExpr>(
                std::make_unique<ParenExpr>(
                    std::make_unique<MultExpr>(
                        std::make_unique<Int>(2),
                        std::make_unique<Int>(3)
                    )
                )
            ),
            std::make_unique<Int>(4)
    );
    PrintVisitor p;
    tree->accept(p);
    std::cout << "\n";
    return 0;
}