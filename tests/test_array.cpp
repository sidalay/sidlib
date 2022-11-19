#include <iostream>
#include "array.hpp"

template <typename T, size_t S>
void print_static(const sidlib::array<T,S>& array) {
    if (array.size() == 0) {
        std::cout << "static array is empty\n";
        return;
    }
    for (auto& elem : array) {
        std::cout << elem << ' ';
    }
    std::cout << "\n---------------------------------------\n";
}

int main() {
    sidlib::array<int, 5> Data;

    for (size_t i = 0; i < Data.max_size(); ++i) {
        Data[i] = static_cast<int>(i) * 2;
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
    print_static(Data);

    Data.front() = 320;
    Data.back() = 627;
    print_static(Data);

    try {
        std::cout << Data.at(15) << '\n';
    }
    catch (std::out_of_range& err) {
        std::cerr << err.what() << '\n';
    }

    std::cout << "Data is empty: " << (Data.empty() ? "True" : "False") << '\n';

    sidlib::array<int, 5> DataTwo;

    std::cout << "\n[Before Swap]: \n";
    std::cout << "DataOne Array\t: ";
    print_static(Data);
    std::cout << "DataTwo Array\t: ";
    print_static(DataTwo);
    Data.swap(DataTwo);

    std::cout << "\n[After Swap]: \n";
    std::cout << "DataOne Array\t: ";
    print_static(Data);

    std::cout << "DataTwo Array\t: ";
    print_static(DataTwo);

    try {
        Data.insert(5, 3);
        std::cout << "\n\nDataOne[4]: " << Data.at(4);
    }
    catch (std::out_of_range& err) {
        std::cerr << err.what() << '\n';
    }
}