#pragma once
#include "point.hpp"
#include <memory>
#include <iostream>


template <Scalar T>
class Figure {
public:
    virtual T area() const = 0;
    virtual Point<T> center() const = 0;
    
    virtual void read(std::istream& is) = 0;
    virtual void write(std::ostream& os) const = 0;
    virtual void print() const = 0;
    virtual ~Figure() = default;
};

// Перегрузка оператора вывода
template <Scalar T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& figure) {
    figure.write(os);
    return os;
}

// Перегрузка оператора ввода
template <Scalar T>
std::istream& operator>>(std::istream& is, Figure<T>& figure) {
    figure.read(is);
    return is;
}
