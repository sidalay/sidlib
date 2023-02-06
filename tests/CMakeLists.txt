add_library(compile_options INTERFACE)

target_compile_features(compile_options INTERFACE cxx_std_20)
target_compile_options(compile_options INTERFACE
    -mavx -march=native -Wshadow -Wconversion -Werror -Wall -Wextra -Wpedantic -O0
)

add_executable(test_array test_array.cpp)
add_executable(test_darray test_darray.cpp)
add_executable(test_intrinsics test_intrinsics.cpp)

target_link_libraries(test_array PRIVATE static_array compile_options)
target_link_libraries(test_darray PRIVATE dynamic_array compile_options)
target_link_libraries(test_intrinsics PRIVATE intrinsics compile_options)