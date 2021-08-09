#pragma once
#ifndef LIBPDMATRIX_PDMATRIX_
#define LIBPDMATRIX_PDMATRIX_

#include <vector>
#include <type_traits>

template <typename T>
struct Matrix {
    static_assert(std::is_integral_v<T>, "Integral type required");
};

#endif // LIBPDMATRIX_PDMATRIX_
