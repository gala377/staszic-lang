#define BOOST_TEST_MODULE Hello_Tests_Module

#include <string>

#include <boost/test/unit_test.hpp>

#include <hello/hello.hpp>


BOOST_AUTO_TEST_SUITE(Lib_Hello_tests)

using namespace std::string_literals;

BOOST_AUTO_TEST_CASE(make_greeting_is_greeting_a_proper_person) {
    BOOST_TEST("Hello Adam" == hello::make_greeting("Adam"s));
}

BOOST_AUTO_TEST_CASE(make_greeting_returns_proper_msg_for_empty_name) {
    BOOST_TEST(hello::EMPTY_NAME_MSG == hello::make_greeting(""s).c_str());
}

BOOST_AUTO_TEST_SUITE_END()