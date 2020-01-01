#ifndef VISITOR_EVAL_HPP_
#define VISITOR_EVAL_HPP_

#include <optional>

#include <parser/visitor.hpp>

namespace visitor {
    
    class Eval: public ast::Visitor {
    public:
        std::optional<int> result() const;

        void visit(ast::Node& n) override;
        void visit(ast::Program& n) override;
        void visit(ast::Expr& n) override;
        void visit(ast::BinaryExpr& n) override;
        void visit(ast::UnaryExpr& n) override;
        void visit(ast::AddExpr& n) override;
        void visit(ast::MultExpr& n) override;
        void visit(ast::NegExpr& n) override;
        void visit(ast::ParenExpr& n) override;
        void visit(ast::Int& n) override;
    
    protected:
        std::optional<int> res_{};
    };
}

#endif