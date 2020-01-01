#define BOOST_TEST_MODULE LEXER_TESTS

#include <boost/test/unit_test.hpp>

#include<iostream>

#include <lexer/lexer.hpp>
#include <source/string.hpp>

BOOST_AUTO_TEST_SUITE(lexer_tests)

using namespace lexer;
using namespace source;
using namespace std::string_literals;

BOOST_AUTO_TEST_CASE(empty_lexer_returns_end_of_source) {
    auto s = String{""s};
    auto l = Lexer{s};
    BOOST_CHECK(l.curr().type() == Token::Type::EOS);
    BOOST_CHECK(l.peek().type() == Token::Type::EOS);
}

BOOST_AUTO_TEST_CASE(bumping_empty_lexer_once_results_in_end_of_source) {
    auto s = String{""s};
    auto l = Lexer{s};
    l.bump();
    BOOST_CHECK(l.curr().type() == Token::Type::EOS);
    BOOST_CHECK(l.peek().type() == Token::Type::EOS);

}

BOOST_AUTO_TEST_CASE(lexer_identifier_parse_Hello) {
    String s{"Hello"s};
    auto l = Lexer{s};
    BOOST_CHECK(l.curr().type() == Token::Type::IDENTIFIER);
    BOOST_CHECK(l.curr().value() == "Hello");
}

BOOST_AUTO_TEST_CASE(lexer_identifier_parse_Hello13411) {
    String s{"Hello13411"s};
    auto l = Lexer{s};
    BOOST_CHECK(l.curr().type() == Token::Type::IDENTIFIER);
    BOOST_CHECK(l.curr().value() == "Hello13411");
}

BOOST_AUTO_TEST_CASE(lexer_identifiers_parse_Hello_World) {
    String s{"Hello World"s};
    auto l = Lexer{s};
    BOOST_CHECK(l.curr().type() == Token::Type::IDENTIFIER);
    BOOST_CHECK(l.curr().value() == "Hello");
    l.bump();
    BOOST_CHECK(l.curr().type() == Token::Type::IDENTIFIER);
    BOOST_CHECK(l.curr().value() == "World");
}

BOOST_AUTO_TEST_CASE(lexer_identifiers_parse_Hello_multiple_whitespaces_World) {
    String s{"Hello \t\n   \n      \t     \n\nWorld"s};
    auto l = Lexer{s};
    BOOST_CHECK(l.curr().type() == Token::Type::IDENTIFIER);
    BOOST_CHECK(l.curr().value() == "Hello");
    l.bump();
    BOOST_CHECK(l.curr().type() == Token::Type::IDENTIFIER);
    BOOST_CHECK(l.curr().value() == "World");
}

BOOST_AUTO_TEST_CASE(lexer_parse_whitespaces_at_front) {
    String s{"\n\t     \t\n\n\n   \n\n     \n\t\t \t \t\n        "s};
    auto l = Lexer{s};
    BOOST_CHECK(l.curr().type() == Token::Type::EOS);
}

BOOST_AUTO_TEST_CASE(lexer_parse_simple_function) {
    String s{"def func() => 1"s};
    auto l = Lexer{s};
    BOOST_CHECK(l.curr().type() == Token::Type::FUNCTION_DEF);
    BOOST_CHECK(l.peek().type() == Token::Type::IDENTIFIER);
    BOOST_CHECK(l.peek().type() == Token::Type::BRACKET_OPEN);
    BOOST_CHECK(l.peek().type() == Token::Type::BRACKET_CLOSE);
    BOOST_CHECK(l.peek().type() == Token::Type::ARROW);
    BOOST_CHECK(l.peek().type() == Token::Type::INTEGER);
}

BOOST_AUTO_TEST_SUITE_END()