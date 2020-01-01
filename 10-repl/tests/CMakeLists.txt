add_definitions(-DBOOST_TEST_DYN_LINK)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

if (Boost_FOUND)
    message("Found boost; ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}")
endif()

include_directories(${StaszicLang_SOURCE_DIR}/inc
                    ${Boost_INCLUDE_DIRS})
                    
add_subdirectory(source)
add_subdirectory(lexer)