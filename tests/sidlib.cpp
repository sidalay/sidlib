#include <iostream>
#include "array.hpp"

int main() {
    sidlib::array<int, 10> Data;

    for (size_t i = 0; i < Data.max_size(); ++i) {
        Data[i] = i * 2;
    }
    std::cout << '\n';
    for (size_t i = 0; i < Data.max_size(); ++i) {
        std::cout << Data.at(i) << '\n';
    }
    std::cout << '\n';
    for (auto it = Data.rbegin(); it != Data.rend(); ++it) {
        std::cout << *it << '\n';
    }
    std::cout << "\n Data.front() = " << Data.front();
    std::cout << "\n Data.back() = " << Data.back();

    Data.fill(100);
    for (auto& Num : Data) {
        std::cout << Num << '\n';
    }

    Data.fill(8);

    try {
        std::cout << Data[2] << '\n';
        std::cout << Data.at(15) << '\n';
    }
    catch (std::out_of_range& err) {
        std::cerr << err.what() << '\n';
    }

}