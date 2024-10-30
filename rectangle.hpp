#pragma once
#include "figure.hpp"

template <Scalar T>
class Rectangle : public Figure<T> {
    T width, height;
    std::unique_ptr<Point<T>> center_point;

public:
    Rectangle(T width = 0, T height = 0, T x = 0, T y = 0) 
        : width(width), height(height), center_point(std::make_unique<Point<T>>(x, y)) {}

    T area() const override {
        return width * height;
    }

    Point<T> center() const override {
        return *center_point;
    }

    void write(std::ostream& os) const override {
        os << "Rectangle: Center = (" << center_point->x << ", " << center_point->y 
           << "), Width = " << width << ", Height = " << height << ", Area = " << area();
    }

    void read(std::istream& is) override {
        std::cout << "Enter width and height of rectangle: ";
        is >> width >> height;
        std::cout << "Enter center x and y coordinates of rectangle: ";
        is >> center_point->x >> center_point->y;
    }
};
