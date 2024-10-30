#pragma once
#include "figure.hpp"
#include <limits>
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
        while (!(is >> side)) {
            std::cout << "Invalid input. Please enter a number for the side length: ";
            is.clear();  // Сбрасываем ошибочное состояние потока
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очищаем остаток строки
        }

        std::cout << "Enter center x and y coordinates of square: ";
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

