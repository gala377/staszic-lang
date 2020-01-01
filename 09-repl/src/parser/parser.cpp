#include <stdexcept>
#include <memory>
#include <string>
#include <iostream>

#include <parser/parser.hpp>

parser::Parser::Parser(lexer::Lexer lexer): lexer_(lexer) {}

ast::AST parser::Parser::parse() {
    auto root = std::make_unique<ast::Program>();
    // std::cout << "Parsing program\n";
    for(auto expr = parse_expr(); expr; expr = parse_expr()) {
        root->add_node(std::move(expr));
    }
    // std::cout << "Program parsed\n";
    return AST(std::move(root));
}

std::unique_ptr<ast::Expr> parser::Parser::parse_expr() {
    // std::cout << "Parsing Expr\n";
    return parse_bin_expr();
}
std::unique_ptr<ast::Expr> parser::Parser::parse_bin_expr() {
    // std::cout << "Parsing BinExpr\n";
    return parse_add_expr();
}

std::unique_ptr<ast::Expr> parser::Parser::parse_add_expr() {
    // std::cout << "Parsing AddExpr\n";
    auto lhs = parse_mult_expr();
    if(!lhs) {
        // std::cout << "AddExpr couldn't parse lhs\n";
        return nullptr;
    }
    std::unique_ptr<Expr> rhs = nullptr;
    while(parse_token(lexer::Token::Type::PLUS)) {
        rhs = parse_mult_expr();
        if(!rhs) {
            throw std::runtime_error("Expression expected after + operator");
        }
        lhs = std::make_unique<ast::AddExpr>(
            std::move(lhs), std::move(rhs));
    } 
    // std::cout << "Parsed AddExpr\n";
    return lhs;
}

std::unique_ptr<ast::Expr> parser::Parser::parse_mult_expr() {
    // std::cout << "Parsing MultExpr\n";
    auto lhs = parse_unary_expr();
    if(!lhs) {
        // std::cout << "MultExpr could not parse lhs\n";
        return nullptr;
    }
    std::unique_ptr<Expr> rhs = nullptr;
    while(parse_token(lexer::Token::Type::MULTIPLY)) {
        rhs = parse_unary_expr();
        if(!rhs) {
            throw std::runtime_error("Expression expected after * operator");
        }
        lhs = std::make_unique<ast::MultExpr>(
            std::move(lhs), std::move(rhs));
    } 
    // std::cout << "MultExpr parsed\n";
    return lhs;
}


std::unique_ptr<ast::Expr> parser::Parser::parse_unary_expr() {
    // std::cout << "Parsing UnaryExpr\n";
    return parse_neg_expr();
}
std::unique_ptr<ast::Expr> parser::Parser::parse_neg_expr() {
    // std::cout << "Parsing NegExpr\n";
    if(!parse_token(lexer::Token::Type::MINUS)) {
        // std::cout << "No unary minus operator\n";
        return parse_paren_expr();
    }
    auto rhs = parse_paren_expr();
    if(!rhs) {
        throw std::runtime_error("Expression expected after unary - operator");
    }
    // std::cout << "UnaryExpr parsed\n";
    return std::make_unique<NegExpr>(std::move(rhs));
}
std::unique_ptr<ast::Expr> parser::Parser::parse_paren_expr() {
    // std::cout << "Parsing ParenExpr\n";
    if(!parse_token(lexer::Token::Type::BRACKET_OPEN)) {
        // std::cout << "No open bracket\n";
        return parse_int_lit();
    }
    auto expr = parse_expr();
    if(!expr) {
        throw std::runtime_error("Expression expected after opening bracket");
    }
    if(!parse_token(lexer::Token::Type::BRACKET_CLOSE)) {
        throw std::runtime_error("Unclosed prenthesis");
    }
    // std::cout << "Parsed ParenExpr\n";
    return std::make_unique<ast::ParenExpr>(std::move(expr));
}
std::unique_ptr<ast::Expr> parser::Parser::parse_int_lit() {
    auto val = parse_token(lexer::Token::Type::INTEGER);
    // std::cout << "Parsing Int\n";
    if(val) {
        // std::cout << "Parsed int " << val->value() << "\n";
    }
    return val ? std::make_unique<Int>(std::stoi(val->value())) : nullptr;
}

std::optional<lexer::Token> parser::Parser::parse_token(lexer::Token::Type type) {
    // std::cout << "Parsing token\n";
    // std::cout << "Curr token value " << lexer_.curr().value() << "\n";
    if(auto curr = lexer_.curr(); curr.type() == type) {
        lexer_.bump();
        // std::cout << "Parsed token " << curr.value() << "\n";
        return {curr};
    }
    return std::nullopt;
}