#include <iostream>
#include "simd.hpp"

namespace sl = sidlib;

int main() {
    // sidlib::float_256 myFloat{1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f};
    sidlib::int_256 myInt{_mm256_set1_epi32(2)};
    // sidlib::double_256 myDouble{3.0,3.0,3.0,3.0};

    // sl::float_256 evens{2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f};
    // sl::float_256 odds{1.0f, 3.0f, 5.0f, 7.0f, 9.0f, 11.0f, 13.0f, 15.0f};

    // sl::float_256 result{_mm256_sub_ps(evens, odds)};

    // float *r = (float*)&result;
    int* test = (int*)&myInt;

    std::cout << "Result: ";
    for (int  i = 0; i < 8; i++) {
        std::cout << test[i] << " ";
    }
    std::cout << std::endl;
}