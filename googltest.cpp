#include <gtest/gtest.h>
#include <iostream>
#include "trapezoid.hpp"
#include "square.hpp"
#include "rectangle.hpp"
#include "array.hpp"

// Тест для добавления и проверки площади
TEST(ArrayTest, AddAndArea) {
    Array<std::shared_ptr<Figure<double>>> figures;
    
    figures.add(std::make_shared<Square<double>>(5.0, 0.0, 0.0));
    figures.add(std::make_shared<Rectangle<double>>(3.0, 4.0, 1.0, 1.0));
    figures.add(std::make_shared<Trapezoid<double>>(6.0, 4.0, 5.0, 2.0, 2.0));

    double expected_total_area = 5.0 * 5.0 + 3.0 * 4.0 + 0.5 * (6.0 + 4.0) * 5.0;
    EXPECT_DOUBLE_EQ(figures.totalArea(), expected_total_area);
}


// Тест для удаления фигуры по индексу
TEST(ArrayTest, RemoveFigure) {
    Array<std::shared_ptr<Figure<double>>> figures;

    figures.add(std::make_shared<Square<double>>(5.0, 0.0, 0.0));
    figures.add(std::make_shared<Rectangle<double>>(3.0, 4.0, 1.0, 1.0));
    figures.add(std::make_shared<Trapezoid<double>>(6.0, 4.0, 5.0, 2.0, 2.0));

    figures.remove(1); // Удаление второй фигуры (Rectangle)

    ASSERT_EQ(figures.getSize(), 2); // Проверка, что осталось 2 фигуры

    double expected_total_area = 5.0 * 5.0 + 0.5 * (6.0 + 4.0) * 5.0;
    EXPECT_DOUBLE_EQ(figures.totalArea(), expected_total_area);
}


// Тест для увеличения емкости массива
TEST(ArrayTest, ResizeTest) {
    Array<std::shared_ptr<Figure<double>>> figures(2);

    figures.add(std::make_shared<Square<double>>(5.0, 0.0, 0.0));
    figures.add(std::make_shared<Rectangle<double>>(3.0, 4.0, 1.0, 1.0));
    figures.add(std::make_shared<Trapezoid<double>>(6.0, 4.0, 5.0, 2.0, 2.0)); 

    ASSERT_EQ(figures.getSize(), 3);

    double expected_total_area = 5.0 * 5.0 + 3.0 * 4.0 + 0.5 * (6.0 + 4.0) * 5.0;
    EXPECT_DOUBLE_EQ(figures.totalArea(), expected_total_area);
}
