#pragma once
#include "figure.hpp"
#include <limits>
template <Scalar T>
class Trapezoid : public Figure<T> {
    T base1, base2, height;
    std::unique_ptr<Point<T>> center_point;

public:
    Trapezoid(T base1 = 0, T base2 = 0, T height = 0, T x = 0, T y = 0) 
        : base1(base1), base2(base2), height(height), center_point(std::make_unique<Point<T>>(x, y)) {}

    T area() const override {
        return 0.5 * (base1 + base2) * height;
    }

    Point<T> center() const override {
        return *center_point;
    }

    void write(std::ostream& os) const override {
        os << "Trapezoid: Center = (" << center_point->x << ", " << center_point->y 
           << "), Base1 = " << base1 << ", Base2 = " << base2 << ", Height = " << height 
           << ", Area = " << area();
    }

    void read(std::istream& is) override {
        std::cout << "Enter lengths of base1, base2, and height of trapezoid: ";
        while (!(is >> base1 >> base2 >> height)) {
            std::cout << "Invalid input. Please enter numbers for base1, base2, and height: ";
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    
        std::cout << "Enter center x and y coordinates of trapezoid: ";
        while (!(is >> center_point->x >> center_point->y)) {
            std::cout << "Invalid input. Please enter numbers for x and y coordinates: ";
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    void print() const override {
    write(std::cout);
    std::cout << std::endl;
}
};

