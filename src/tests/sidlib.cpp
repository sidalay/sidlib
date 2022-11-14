#include <array.hpp>
#include <iostream>
#include <array>

int main() {
    sidlib::array<int, 10> Data;

    for (size_t i = 0; i < Data.max_size(); ++i) {
        Data[i] = i * 2;
    }
    for (size_t i = 0; i < Data.max_size(); ++i) {
        std::cout << Data.at(i) << '\n';
    }
}