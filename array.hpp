#pragma once
#include <memory>
#include <cstddef>
#include <iostream>

template <typename T>
class Array {
    std::shared_ptr<T[]> data;
    std::size_t size;
    std::size_t capacity;

public:
    Array(std::size_t initial_capacity = 2) 
        : data(std::shared_ptr<T[]>(new T[initial_capacity])), size(0), capacity(initial_capacity) {}

    void add(const T& element) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        data[size++] = element;
    }

    void remove(std::size_t index) {
        if (index >= size) return;
        for (std::size_t i = index; i < size - 1; ++i) {
            data[i] = std::move(data[i + 1]);
        }
        --size;
    }

    T& operator[](std::size_t index) const {
        return data[index];
    }

    std::size_t getSize() const {
        return size;
    }

    double totalArea() const {
        double total = 0;
        for (std::size_t i = 0; i < size; ++i) {
            total += data[i]->area();
        }
        return total;
    }

private:
    void resize(std::size_t new_capacity) {
        std::shared_ptr<T[]> new_data(new T[new_capacity]);
        for (std::size_t i = 0; i < size; ++i) {
            new_data[i] = std::move(data[i]);
        }
        data = std::move(new_data);
        capacity = new_capacity;
    }
};
