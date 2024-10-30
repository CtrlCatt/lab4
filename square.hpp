#pragma once
#include "figure.hpp"

template <Scalar T>
class Square : public Figure<T> {
    T side;
    std::unique_ptr<Point<T>> center_point;

public:
    Square(T side = 0, T x = 0, T y = 0) 
        : side(side), center_point(std::make_unique<Point<T>>(x, y)) {}

    T area() const override {
        return side * side;
    }

    Point<T> center() const override {
        return *center_point;
    }

    
    void write(std::ostream& os) const override {
        os << "Square: Center = (" << center_point->x << ", " << center_point->y 
           << "), Side = " << side << ", Area = " << area();
    }

    
    void read(std::istream& is) override {
        std::cout << "Enter side length of square: ";
        is >> side;
        std::cout << "Enter center x and y coordinates of square: ";
        is >> center_point->x >> center_point->y;
    }
};

