add_library(dynamic_array INTERFACE dArray.hpp)
target_include_directories(dynamic_array INTERFACE .)

target_link_libraries(dynamic_array INTERFACE 
    format
)