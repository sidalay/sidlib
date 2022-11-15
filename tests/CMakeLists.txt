add_executable(sidlib_tests array_test.cpp)

target_compile_features(sidlib_tests PRIVATE cxx_std_20)
target_compile_options(sidlib_tests PRIVATE -Werror -Wall -Wextra -Wpedantic -O0)

target_link_libraries(sidlib_tests PRIVATE 
    static_array 
    dynamic_array
    map 
    queue 
    stack 
    string 
    format
)