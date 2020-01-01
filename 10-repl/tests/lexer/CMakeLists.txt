add_executable(lexer_tests lexer_tests.cpp)
target_link_libraries(lexer_tests
    Lexer
    Source
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)