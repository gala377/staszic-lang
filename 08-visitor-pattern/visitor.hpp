#ifndef __VISITOR_HPP__
#define __VISITOR_HPP__

#include "nodes.hpp"


namespace nodes {
    class Expr;
    class BinaryExpr;
    class UnaryExpr;
    class AddExpr;
    class MultExpr;
    class NegExpr;
    class ParenExpr;
    class Int;
}


class Visitor {
public:
    virtual void visit(nodes::Expr& n) = 0;
    virtual void visit(nodes::BinaryExpr& n) = 0;
    virtual void visit(nodes::UnaryExpr& n) = 0;
    virtual void visit(nodes::AddExpr& n) = 0;
    virtual void visit(nodes::MultExpr& n) = 0;
    virtual void visit(nodes::NegExpr& n) = 0;
    virtual void visit(nodes::ParenExpr& n) = 0;
    virtual void visit(nodes::Int& n) = 0;
};

#endif