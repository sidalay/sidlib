#include <iostream>
#include <string>
#include "dArray.hpp"

template <typename T>
void print_dynamic(const sidlib::darray<T>& darray) {
    if (darray.size() == 0) {
        std::cout << "dynamic array is empty";
    }
    for (auto& elem : darray) {
        std::cout << elem << ' ';
    }
    std::cout << "\n---------------------------------------\n";
}

template <typename T>
void print_capacity(const sidlib::darray<T>& darray) {
    std::cout << "data.size()\t: " << darray.size() << '\n';
    std::cout << "data.capacity()\t: " << darray.capacity() << '\n';
    std::cout << "---------------------------------------\n";
}

int main() {
    sidlib::darray<std::string> data;

    // We can observe the capacity of data expanding
    print_dynamic(data);
    print_capacity(data);

    data.push_back("sid");
    data.push_back("loves");
    data.push_back("c++");

    print_dynamic(data);
    print_capacity(data);

    data.push_back("adding");
    data.push_back("some");
    data.push_back("more");
    data.push_back("elements");
    
    print_dynamic(data);
    print_capacity(data);
    // -----------------------------------------------

}