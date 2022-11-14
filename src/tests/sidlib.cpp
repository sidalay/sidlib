#include <array.hpp>
#include <iostream>
#include <array>

int main() {
    sidlib::array<int, 10> Data;

    for (unsigned int i = 0; i < Data.max_size(); ++i) {
        Data[i] = i * 2;
    }
    for (unsigned int i = 0; i < Data.max_size(); ++i) {
        std::cout << Data[i] << '\n';
    }
}