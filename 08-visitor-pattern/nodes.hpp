#ifndef __NODES_HPP__
#define __NODES_HPP__

#include "uptr.hpp"
#include "visitor.hpp"
#include <stdexcept>

namespace nodes {

    class Expr {
    public:
        virtual void accept(Visitor& v) {
            v.visit(*this);
        }
    };

    class BinaryExpr: public Expr {
    public:
        BinaryExpr(
            uptr<Expr>&& lhs,
            uptr<Expr>&& rhs
        ): lhs_(std::move(lhs)), rhs_(std::move(rhs)) {} 

        void accept(Visitor &v) override {
            v.visit(*this);
        }

        uptr<Expr> lhs_;
        uptr<Expr> rhs_;
    };

    class UnaryExpr: public Expr {
    public:
        UnaryExpr(
            uptr<Expr> expr
        ): expr_(std::move(expr)) {};

        void accept(Visitor &v) override {
            v.visit(*this);
        }

        uptr<Expr> expr_;
    };

    class AddExpr: public BinaryExpr {
    public:
        using BinaryExpr::BinaryExpr;

        void accept(Visitor &v) override {
            v.visit(*this);
        }
    };

    class MultExpr: public BinaryExpr {
    public:
        using BinaryExpr::BinaryExpr;

        void accept(Visitor &v) override {
            v.visit(*this);
        }
    };

    class NegExpr: public UnaryExpr {
    public:
        using UnaryExpr::UnaryExpr;

        void accept(Visitor &v) override {
            v.visit(*this);
        }
    };


    class ParenExpr: public Expr {
    public:
        ParenExpr(uptr<Expr> expr): expr_(std::move(expr)) {};

        void accept(Visitor &v) override {
            v.visit(*this);
        }

        uptr<Expr> expr_;
    };

    class Int: public Expr {
    public:
        Int(int v): v_(v) {};

        void accept(Visitor &v) override {
            v.visit(*this);
        }

        int v_;
    };
}


#endif