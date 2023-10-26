#pragma once

#include <vector>
#include <iostream>

template <typename T>
class Vector2D : public std::vector<T>
{
public:
    int iSize[2]; // [0] = width, [1] = height

    Vector2D(int size): std::vector<int>(size * size);
    Vector2D(int width, int height): std::vector<int>(width* height);

    T& operator()(int row, int col);
    T getValue(int row, int col);
    void setValue(int row, int col, T value);

    int getSize();
    void resize(int size);
    void resize(int width, int height);
};