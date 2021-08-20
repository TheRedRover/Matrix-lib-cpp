#pragma once

#ifndef LIBPDMATRIX_PDMATRIX_
#define LIBPDMATRIX_PDMATRIX_

#include <cstddef>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <type_traits>
#include <vector>
#include <x86intrin.h>

template <typename T> struct Matrix {
  static_assert(std::is_arithmetic<T>::value, "Arithmetic type is required");
  using matrix = std::vector<T>;

private:
  matrix matrix_;
  size_t cols_;
  size_t rows_;

public:
  Matrix<T>(std::initializer_list<T> l, size_t rows, size_t cols)
      : matrix_(l), rows_(rows), cols_(cols){};

  Matrix<T>(const Matrix<T> &m)
      : matrix_(m.matrix_), rows_(m.rows()), cols_(m.cols()){};

  Matrix<T>(size_t rows, size_t cols): rows_(rows), cols_(cols)
    {
        matrix_ = std::vector<T>(rows_*cols_, 0.0);
    }


  auto cols() const -> size_t { return cols_; }

  auto rows() const -> size_t { return rows_; }

  auto operator()(const size_t i, size_t j) -> T & {
    return matrix_[i * cols() + j];
  };

  auto operator+=(const Matrix<T> &m) -> Matrix<T> & {
    if (!(this->rows() == m.rows() && this->cols() == m.cols()))
      throw std::invalid_argument("matrices have different size");
    for (auto i = matrix_.begin(), j = m.matrix_.begin(); i != matrix_.end();
         ++i, ++j) {
      *i = *i + *j;
    }
    return * this;
  }

  auto operator-=(const Matrix<T> &m) -> Matrix<T> & {
    if (!(this->rows() == m.rows() && this->cols() == m.cols()))
      throw std::invalid_argument("matrices have different size");
    for (auto i = matrix_.begin(), j = m.matrix_.begin(); i != matrix_.end();
         ++i, ++j) {
      *i = *i - *j;
    }
    return * this;
  }

  Matrix<T> operator+(Matrix<T> & m) const
  {
    Matrix<T> res = Matrix<T>(rows(), cols());
    if (!(this->rows() == m.rows() && this->cols() == m.cols()))
      throw std::invalid_argument("matrices have different size");
    auto N = rows()*cols(); 
    const auto alignedN = N - N % 8;
      for (auto i = 0; i < alignedN; i+=8) {
          _mm_storeu_pd(&res.matrix_[i], 
                  _mm_add_pd(_mm_loadu_pd(&matrix_[i]), 
                  _mm_loadu_pd(&m.matrix_[i])));
      }
      for (auto i = alignedN; i < N; ++i) {
          res.matrix_[i] = matrix_[i] + m.matrix_[i];
      }
      return res;
    
  }
};

template <typename T>
auto operator<<(std::ostream &os, Matrix<T> &m) -> std::ostream & {
  for (auto i = 0; i < m.rows(); ++i) {
    for (auto j = 0; j < m.cols(); ++j) {
      os << std::setprecision(6) << m(i, j) << "\t";
    }
    os << "\n\n";
  }
  return os;
}

#endif // LIBPDMATRIX_PDMATRIX_
