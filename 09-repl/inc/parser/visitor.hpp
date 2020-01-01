#ifndef VISITOR_VISITOR_HPP_
#define VISITOR_VISITOR_HPP_

#include <parser/nodes.hpp>

namespace ast {
    class Node;
    class Program;
    class Expr;
    class BinaryExpr;
    class UnaryExpr;
    class AddExpr;
    class MultExpr;
    class NegExpr;
    class ParenExpr;
    class Int;

    class Visitor {
    public:
        virtual void visit(Node& n) = 0;
        virtual void visit(Program& n) = 0;
        virtual void visit(Expr& n) = 0;
        virtual void visit(BinaryExpr& n) = 0;
        virtual void visit(UnaryExpr& n) = 0;
        virtual void visit(AddExpr& n) = 0;
        virtual void visit(MultExpr& n) = 0;
        virtual void visit(NegExpr& n) = 0;
        virtual void visit(ParenExpr& n) = 0;
        virtual void visit(Int& n) = 0;
    };

}
#endif