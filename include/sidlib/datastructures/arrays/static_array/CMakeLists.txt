add_library(static_array INTERFACE array.hpp)
target_include_directories(static_array INTERFACE .)

target_link_libraries(static_array INTERFACE 
    format
)

