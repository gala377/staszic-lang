add_executable(source_tests string_tests.cpp)
target_link_libraries(source_tests
    Source
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)