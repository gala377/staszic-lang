add_subdirectory(hello)

add_executable(spc main.cc)
target_link_libraries(spc Hello)