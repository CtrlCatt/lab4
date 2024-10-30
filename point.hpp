#pragma once
#include <concepts>

// Концепт, проверяющий, что T — скалярный тип
template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

template <Scalar T>
class Point {
public:
    T x, y;

    Point(T x = 0, T y = 0) : x(x), y(y) {}
};
