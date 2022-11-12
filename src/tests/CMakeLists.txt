add_executable(tests sidlib.cpp)

target_link_libraries(tests PRIVATE 
    array 
    map 
    queue 
    stack 
    string 
    vector
)