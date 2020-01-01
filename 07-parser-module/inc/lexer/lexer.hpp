#ifndef LEXER_LEXER_HPP_
#define LEXER_LEXER_HPP_

#include <string>

#include "source/source.hpp"

namespace lexer {

    class Token {
      public:
        enum class Type {
            ARROW,
            BRACKET_CLOSE,
            BRACKET_OPEN,
            COMMA,
            DIVIDE,
            ELSE,
            EOS,
            EQUAL,
            FUNCTION_DEF,
            GREATER,
            IDENTIFIER,
            IF,
            INEQUAL,
            INTEGER,
            INVALID,
            LESS,
            MINUS,
            MULTIPLY,
            PLUS,
            THEN,
        };
        
        Token(Type type, std::string value);
        ~Token() = default;

        Type type() const;
        const std::string& value() const;
    private:
        Type type_;
        std::string value_;
    };

    class Lexer {
      public:
        Lexer(source::Source& source);
        ~Lexer() = default;

        Token curr();
        Token peek();
        void bump();
      private:
        Token readToken();

        source::Source& source_;
        Token token_;
    };
}

#endif
