add_executable(tests sidlib.cpp)

target_compile_features(tests PRIVATE cxx_std_20)
target_compile_options(tests PRIVATE -Werror -Wall -Wextra -Wpedantic)

target_link_libraries(tests PRIVATE 
    array 
    map 
    queue 
    stack 
    string 
    vector
)