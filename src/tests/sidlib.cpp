#include <array.hpp>
#include <iostream>

int main() {
    sidlib::array<int, 10> Data;
    for (unsigned int i = 0; i < Data.Size(); ++i) {
        Data[i] = i * 2;
    }
    for (unsigned int i = 0; i < Data.Size(); ++i) {
        std::cout << Data[i] << '\n';
    }
}