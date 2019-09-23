#define BOOST_TEST_MODULE SOURCE_TESTS

#include <string>

#include <boost/test/unit_test.hpp>

#include <source/string.hpp>


BOOST_AUTO_TEST_SUITE(string_source_tests)

using namespace source;
using namespace std::string_literals;

BOOST_AUTO_TEST_CASE(empty_source_returns_end_of_text) {
    String s{""s};
    BOOST_TEST(s.curr() == END_OF_TEXT);
    BOOST_TEST(s.peek() == END_OF_TEXT);
}

BOOST_AUTO_TEST_CASE(bumping_empty_source_once_results_in_end_of_text) {
    String s{""s};
    s.bump();
    BOOST_TEST(s.curr() == END_OF_TEXT);
    BOOST_TEST(s.peek() == END_OF_TEXT);

}

BOOST_AUTO_TEST_CASE(bumping_empty_source_several_times_results_in_end_of_text) {
    String s{""s};
    s.bump(); s.bump(); s.bump();
    BOOST_TEST(s.curr() == END_OF_TEXT);
    BOOST_TEST(s.peek() == END_OF_TEXT);
}

BOOST_AUTO_TEST_CASE(not_empty_source_initializes_to_the_first_string_character) {
    String s{"Hello"s};
    BOOST_TEST(s.curr() == 'H');
    BOOST_TEST(s.peek() == 'e');
}

BOOST_AUTO_TEST_CASE(bumping_non_empty_source_shifts_character) {
    String s{"Hello"s};
    s.bump();
    BOOST_TEST(s.curr() == 'e');
    BOOST_TEST(s.peek() == 'l');
}

BOOST_AUTO_TEST_CASE(bumping_before_the_end_returns_last_character_end_peeks_end_fo_text) {
    String s{"Hello"s};
    s.bump(); s.bump(); s.bump(); s.bump();
    BOOST_TEST(s.curr() == 'o');
    BOOST_TEST(s.peek() == END_OF_TEXT);
}

BOOST_AUTO_TEST_CASE(bumping_past_the_source_sets_current_character_on_the_end_of_text) {
    String s{"Hello"s};
    s.bump(); s.bump(); s.bump(); s.bump(); s.bump();
    BOOST_TEST(s.curr() == END_OF_TEXT);
    BOOST_TEST(s.peek() == END_OF_TEXT);
}

BOOST_AUTO_TEST_CASE(bumping_several_times_past_the_end_of_source_sets_the_character_on_the_end_of_text) {
    String s{"Hello"s};
    for(int i = 0; i < 100; ++i) {
        s.bump();
    }
    BOOST_TEST(s.curr() == END_OF_TEXT);
    BOOST_TEST(s.peek() == END_OF_TEXT);
}

BOOST_AUTO_TEST_SUITE_END()