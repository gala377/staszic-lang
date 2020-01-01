#ifndef PARSER_NODES_HPP_
#define PARSER_NODES_HPP_

#include <memory>
#include <vector>

#include <parser/visitor.hpp>

namespace ast {

    class Visitor;

    class Node {
    public:
        virtual void accept(Visitor& v) = 0;
        virtual ~Node() = default;
    };

    class Program: public Node {
    public:
        Program() = default;
        Program(std::vector<std::unique_ptr<Node>> nodes);

        void add_node(std::unique_ptr<Node> node);

        std::vector<std::unique_ptr<Node>> nodes;

        void accept(Visitor& v) override;
    };

    class Expr: public Node {};

    class BinaryExpr: public Expr {
    public:
        BinaryExpr(
            std::unique_ptr<Expr>&& lhs,
            std::unique_ptr<Expr>&& rhs
        ): lhs_(std::move(lhs)), rhs_(std::move(rhs)) {} 

        std::unique_ptr<Expr> lhs_;
        std::unique_ptr<Expr> rhs_;

        void accept(Visitor& v) override;
    };

    class UnaryExpr: public Expr {
    public:
        UnaryExpr(
            std::unique_ptr<Expr> expr
        ): expr_(std::move(expr)) {};

        std::unique_ptr<Expr> expr_;

        void accept(Visitor& v) override;
    };

    class AddExpr: public BinaryExpr {
    public:
        using BinaryExpr::BinaryExpr;
        
        void accept(Visitor& v) override;
    };

    class MultExpr: public BinaryExpr {
    public:
        using BinaryExpr::BinaryExpr;

        void accept(Visitor& v) override;
    };

    class NegExpr: public UnaryExpr {
    public:
        using UnaryExpr::UnaryExpr;

        void accept(Visitor& v) override;
    };

    class ParenExpr: public Expr {
    public:
        ParenExpr(std::unique_ptr<Expr> expr): expr_(std::move(expr)) {};

        std::unique_ptr<Expr> expr_;

        void accept(Visitor& v) override;
    };

    class Int: public Expr {
    public:
        Int(int v): v_(v) {};

        int v_;

        void accept(Visitor& v) override;
    };

}

#endif