#ifndef PARSER_PARSER_HPP_
#define PARSER_PARSER_HPP_

#include <memory>
#include <optional>

#include <parser/ast.hpp>
#include <lexer/lexer.hpp>

namespace parser {

    using namespace ast;
    using namespace lexer;

    class Parser {
    public:
        Parser(Lexer lexer);

        AST parse();

    private:
        Lexer lexer_;

        std::unique_ptr<Expr> parse_expr();
        std::unique_ptr<Expr> parse_bin_expr();
        std::unique_ptr<Expr> parse_unary_expr();
        std::unique_ptr<Expr> parse_add_expr();
        std::unique_ptr<Expr> parse_mult_expr();
        std::unique_ptr<Expr> parse_neg_expr();
        std::unique_ptr<Expr> parse_paren_expr();
        std::unique_ptr<Expr> parse_int_lit();

        std::optional<Token> parse_token(Token::Type type);
    };
}

#endif