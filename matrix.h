//
// Created by wmy on 2023/11/12.
//

#ifndef CPPCG_MATRIX_H
#define CPPCG_MATRIX_H

#include <iostream>
#include "vector.h"

template <size_t m, size_t n>
class mat {
private:
    float _vals[m * n];

public:
    constexpr unsigned int shape(unsigned int i) {
        return i ? n : m;
    }

    float* operator[](unsigned int i) {
        return _vals + i * n;
    }

    mat<m, n>& operator=(const mat<m, n>& matrix) {
        if (this == &matrix) return *this;
        memcpy(_vals, matrix, m * n * sizeof(float));
        return *this;
    }

    void print() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << _vals[i * n + j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

template <size_t n>
class mat<1, n> {
private:
    float _vals[n]{};

public:
    constexpr unsigned int shape(unsigned int i) {
        return i ? n : 1;
    }

    mat() = default;

    explicit mat(vec<n> vector) {
        memcpy(_vals, &(vector[0]), n * sizeof(float));
    }

    mat<1, n>& operator=(const mat<1, n>& matrix) {
        if (this == &matrix) return *this;
        memcpy(_vals, matrix[0], n * sizeof(float));
        return *this;
    }

    float* operator[](unsigned int i) {
        return _vals + i * n;
    }

    void print() {
        for (int i = 0; i < 1; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << _vals[i * n + j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif //CPPCG_MATRIX_H
