#include <iostream>
#include "array.hpp"

int main() {
    sidlib::array<int, 5> Data;

    for (size_t i = 0; i < Data.max_size(); ++i) {
        Data[i] = i * 2;
    }
    std::cout << "Print using normal for-loop\t: ";
    for (size_t i = 0; i < Data.max_size(); ++i) {
        std::cout << Data.at(i) << ' ';
    }
    std::cout << "\nPrint using reverse iterators\t: ";
    for (auto it = Data.rbegin(); it != Data.rend(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << "\nPrint using ranged based loop\t: ";
    Data.fill(100);
    for (auto& Num : Data) {
        std::cout << Num << ' ';
    }

    Data.front() = 320;
    Data.back() = 627;
    std::cout << "\n\nData.front() = " << Data.front();
    std::cout << "\nData.back()  = " << Data.back() << '\n';

    try {
        std::cout << Data.at(15) << '\n';
    }
    catch (std::out_of_range& err) {
        std::cerr << err.what() << '\n';
    }

    std::cout << "Data is empty: " << (Data.empty() ? "True" : "False") << '\n';

    sidlib::array<int, 5> DataTwo;

    std::cout << "\n\nBefore Swap: \n";
    std::cout << "\nDataOne Array\t: ";
    for (auto& Num:Data) {
        std::cout << Num << ' ';
    }
    std::cout << "\nDataTwo Array\t: ";
    for (auto& Num:DataTwo) {
        std::cout << Num << ' ';
    }

    Data.swap(DataTwo);

    std::cout << "\n\nAfter Swap: \n";
    std::cout << "\nDataOne Array\t: ";
    for (auto& Num:Data) {
        std::cout << Num << ' ';
    }
    std::cout << "\nDataTwo Array\t: ";
    for (auto& Num:DataTwo) {
        std::cout << Num << ' ';
    }

    try {
        Data.insert(5, 3);
        std::cout << "\n\nDataOne[4]: " << Data.at(4);
    }
    catch (std::out_of_range& err) {
        std::cerr << err.what() << '\n';
    }
}