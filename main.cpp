#include "array.hpp"
#include "square.hpp"
#include "rectangle.hpp"
#include "trapezoid.hpp"
#include <memory>
#include <iostream>
#include <limits>


void addFigure(Array<std::shared_ptr<Figure<double>>>& figures) {
    char choice;
    std::cout << "Choose a figure to add:\n";
    std::cout << "s: Square\n";
    std::cout << "r: Rectangle\n";
    std::cout << "t: Trapezoid\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    std::shared_ptr<Figure<double>> figure;

    // Создаем нужную фигуру в зависимости от выбора пользователя
    if (choice == 's') {
        figure = std::make_shared<Square<double>>();
    } else if (choice == 'r') {
        figure = std::make_shared<Rectangle<double>>();
    } else if (choice == 't') {
        figure = std::make_shared<Trapezoid<double>>();
    } else {
        std::cout << "Invalid choice! Returning to main menu.\n";
        return;
    }

    // Попытка ввода параметров фигуры
    std::cout << "Enter the parameters for the selected figure:\n";
    if (!(std::cin >> *figure)) {  // Используем перегруженный оператор >> для ввода
        std::cout << "Invalid input. Returning to main menu.\n";
        std::cin.clear();  // Сбрасываем ошибочное состояние
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очищаем буфер до конца строки
        return;
    }

    // Если ввод успешный, добавляем фигуру в массив
    figures.add(figure);
    std::cout << "Figure added successfully.\n";
}

void deleteFigure(Array<std::shared_ptr<Figure<double>>>& figures) {
    std::size_t index;
    std::cout << "Enter the index of the figure to delete: ";
    while (!(std::cin >> index) || index >= figures.getSize()) {
        std::cout << "Invalid input. Returning to main menu\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    figures.remove(index);
    std::cout << "Figure at index " << index << " deleted.\n";
}

void printFigures(const Array<std::shared_ptr<Figure<double>>>& figures) {
    std::cout << "\nFigures in array:\n";
    for (std::size_t i = 0; i < figures.getSize(); ++i) {
        std::cout << "Index " << i << ": ";
        figures[i]->print();
    }
    std::cout << "Total area of all figures: " << figures.totalArea() << "\n";
}

int main() {
    Array<std::shared_ptr<Figure<double>>> figures;
    char choice;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add figure\n";
        std::cout << "2. Delete figure by index\n";
        std::cout << "3. Print all figures\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                addFigure(figures);
                break;
            case '2':
                deleteFigure(figures);
                break;
            case '3':
                printFigures(figures);
                break;
            case '4':
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    }

    return 0;
}