add_subdirectory(source)
add_subdirectory(lexer)
add_subdirectory(parser)
add_subdirectory(visitor)

add_executable(spc main.cpp repl.cpp)
target_link_libraries(spc Source)
target_link_libraries(spc Lexer)
target_link_libraries(spc Parser)
target_link_libraries(spc Visitor)