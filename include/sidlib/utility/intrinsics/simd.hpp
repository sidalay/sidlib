#ifndef SIDLIB_SIMD_HPP
#define SIDLIB_SIMD_HPP

#include <immintrin.h>

namespace sidlib
{
    using float_128     = __m128;
    using int_128       = __m128i;
    using double_128    = __m128d;

    using float_128u    = __m128_u;
    using int_128u      = __m128i_u;
    using double_128u   = __m128d_u;

    using float_256     = __m256;
    using int_256       = __m256i;
    using double_256    = __m256d;

    using float_256u    = __m256_u;
    using int_256u      = __m256i_u;
    using double_256u   = __m256d_u;


    struct simd 
    {

    };
}

#endif // SIDLIB_SIMD_HPP