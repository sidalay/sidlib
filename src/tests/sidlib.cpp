#include <array.hpp>
#include <iostream>

int main() {
    sidlib::array<int, 10> Data;
    Data[5] = 10;
    std::cout << Data[5];
}