add_executable(hello_tests hello.cpp)
target_link_libraries(hello_tests
    Hello
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
