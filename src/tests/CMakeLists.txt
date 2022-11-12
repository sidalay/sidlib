add_executable(tests sidlib.cpp)

target_link_libraries(tests PRIVATE 
    array 
    map 
    queue 
    stack 
    string 
    vector
)

target_compile_options(tests PRIVATE -Werror -Wall -Wextra -Wpedantic -std=c++20)