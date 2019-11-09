add_subdirectory(hello)

add_executable(spc main.cpp)
target_link_libraries(spc Hello)