add_subdirectory(source)
add_subdirectory(lexer)

add_executable(spc main.cpp)
target_link_libraries(spc Source)
target_link_libraries(spc Lexer)