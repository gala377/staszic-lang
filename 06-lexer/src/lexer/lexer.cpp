#include "lexer/lexer.hpp"

#include <map>

namespace lexer {
    Token::Token(Token::Type type, std::string value) : type_(type), value_(value) {}
    
    Token::Type Token::type() const {
        return type_;
    }

    const std::string& Token::value() const {
        return value_;
    }

    Lexer::Lexer(source::String source) : source_(source), token_(readToken()) {}

    Token Lexer::curr() {
        return token_;
    }

    Token Lexer::peek() {
        bump();
        return curr();
    }

    void Lexer::bump() {
        if (token_.type() != Token::Type::EOS) {
            token_ = readToken();
        }
    }

    Token Lexer::readToken() {
        static const std::map<std::string, Token::Type> keywords = {
            { "if", Token::Type::IF },
            { "then", Token::Type::THEN },
            { "else", Token::Type::ELSE },
            { "def", Token::Type::FUNCTION_DEF }
        };

        enum class State {
            BEGIN,
            IDENTIFIER_BEGIN,
            INTEGER_BEGIN,
            EQUAL,
            EXCLAMATION,
            END,
            INVALID
        };

        // Will gather whitespaces if is now first token
        static bool gather_whitespaces;
        if (gather_whitespaces) {
            while(source_.curr() == ' ' ||
                  source_.curr() == '\t' ||
                  source_.curr() == '\n') {
                source_.bump();
            }
        } else {
            gather_whitespaces = true;
        }

        Token::Type type = Token::Type::INVALID;
        std::string value = "";

        State state = State::BEGIN;
        while (state != State::END) {
            switch (state) {
            case State::BEGIN:
                if (std::isalpha(source_.curr())) {
                    state = State::IDENTIFIER_BEGIN;
                } else if (std::isdigit(source_.curr())) {
                    state = State::INTEGER_BEGIN;
                } else if (source_.curr() == '=') {
                    state = State::EQUAL;
                } else if (source_.curr() == '!') {
                    state = State::EXCLAMATION;
                } else if (source_.curr() == ')') {
                    type = Token::Type::BRACKET_CLOSE;
                    state = State::END;
                } else if (source_.curr() == '(') {
                    type = Token::Type::BRACKET_OPEN;
                    state = State::END;
                } else if (source_.curr() == ',') {
                    type = Token::Type::COMMA;
                    state = State::END;
                } else if (source_.curr() == '/') {
                    type = Token::Type::DIVIDE;
                    state = State::END;
                } else if (source_.curr() == '>') {
                    type = Token::Type::GREATER;
                    state = State::END;
                } else if (source_.curr() == '<') {
                    type = Token::Type::LESS;
                    state = State::END;
                } else if (source_.curr() == '-') {
                    type = Token::Type::MINUS;
                    state = State::END;
                } else if (source_.curr() == '*') {
                    type = Token::Type::MULTIPLY;
                    state = State::END;
                } else if (source_.curr() == '+') {
                    type = Token::Type::PLUS;
                    state = State::END;
                } else if (source_.curr() == source::END_OF_TEXT) {
                    type = Token::Type::EOS;
                    state = State::END;
                } else {
                    state = State::INVALID;
                }
                value += source_.curr();
                source_.bump();
                break;
            case State::IDENTIFIER_BEGIN:
                    if (std::isalpha(source_.curr()) 
                        || std::isdigit(source_.curr())
                        || source_.curr() == '_') {
                        value += source_.curr();
                        source_.bump();
                    } else {
                        type = Token::Type::IDENTIFIER;
                        state = State::END;
                    }
                break;
            case State::INTEGER_BEGIN:
                    if (std::isdigit(source_.curr())) {
                        value += source_.curr();
                        source_.bump();
                    } else if (source_.curr() == ' ' ||
                               source_.curr() == '\t' ||
                               source_.curr() == '\n' ||
                               source_.curr() == source::END_OF_TEXT) {
                        type = Token::Type::INTEGER;
                        state = State::END;
                    } else {
                        state = State::INVALID;
                        value += source_.curr();
                        source_.bump();
                    }
                break;
            case State::EQUAL:
                if (source_.curr() == '>') {
                    type = Token::Type::ARROW;
                    state = State::END;
                    value += source_.curr();
                    source_.bump();
                } else {
                    type = Token::Type::EQUAL;
                    state = State::END;
                }
                break;
            case State::EXCLAMATION:
                if (source_.curr() == '=') {
                    type = Token::Type::INEQUAL;
                    state = State::END;
                    value += source_.curr();
                    source_.bump();
                } else {
                    state = State::INVALID;
                    value += source_.curr();
                    source_.bump();
                }
                break;
            case State::INVALID:
                if (source_.curr() == ' ' ||
                    source_.curr() == '\t' ||
                    source_.curr() == '\n' ||
                    source_.curr() == source::END_OF_TEXT) {
                    type = Token::Type::INVALID;
                    state = State::END;
                } else {
                    value += source_.curr();
                    source_.bump();
                }
                break;
            case State::END:
                // NOTREACHED();
                break;
            }
        }

        if (type == Token::Type::IDENTIFIER) {
            auto it = keywords.find(value);
            if (it != keywords.end()) {
                type = it->second;
            }
        }

        return Token{type, value};
    }
} // namespace lexer
