//
// Created by wmy on 2023/11/12.
//

#ifndef CPPCG_VECTOR_H
#define CPPCG_VECTOR_H

#include <iostream>

template <size_t n>
class vec {
private:
    float _vals[n]{};

public:
    constexpr unsigned int size() {
        return n;
    }

    vec() = default;

    explicit vec(const float (&vals)[n]) {
        memcpy(_vals, vals, n * sizeof(float));
    }

    vec<n>& operator=(const float (&vals)[n]) {
        memcpy(_vals, vals, n * sizeof(float));
        return *this;
    }

    float& operator[](unsigned int i) {
        return _vals[i];
    }

    const float& operator[](unsigned int i) const {
        return _vals[i];
    }

    void print() {
        for (int i = 0; i < n; i++) {
            std::cout << _vals[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif //CPPCG_VECTOR_H
