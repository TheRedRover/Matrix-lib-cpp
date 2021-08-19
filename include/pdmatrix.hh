#pragma once
#include <cstddef>
#include <initializer_list>
#ifndef LIBPDMATRIX_PDMATRIX_
#define LIBPDMATRIX_PDMATRIX_

#include <vector>
#include <type_traits>



template <typename T>
struct Matrix {
    static_assert(std::is_integral<T>::value, "Integral type required");
    using matrix = std::vector<T>;

private:
    matrix matrix_;
    size_t cols_;
    size_t rows_;

public:
    Matrix<T>(std::initializer_list<T> l, size_t rows, size_t cols): matrix_(l), rows_(rows), cols_(cols){};

    auto cols() const -> size_t { return cols_ ;}

    auto rows() const -> size_t { return rows_;}

    auto operator()(const size_t i, size_t j) -> T&
    {
        return matrix_[i*cols()+j];
    };
};

// template <typename T>
// auto Matrix<T>::cols() const -> 

#endif // LIBPDMATRIX_PDMATRIX_
