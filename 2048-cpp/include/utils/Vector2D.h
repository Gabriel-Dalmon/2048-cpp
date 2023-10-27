#pragma once

#include <vector>

template <typename T>
class Vector2D : public std::vector<T>
{
public:
    int iSize[2]; // [0] = width, [1] = height
    
    Vector2D(int size) : std::vector<T>(size* size) {
        this->iSize[0] = size;
        this->iSize[1] = size;
    };
    Vector2D(int width, int height) : std::vector<T>(width* height) {
        this->iSize[0] = width;
        this->iSize[1] = height;
    };

    int getSingleSize(GridDimension lengthIndex) {
        return this->iSize[lengthIndex];
    };

    void resize(int size) {
        this->resize(size, size);
    };
    void resize(int width, int height) {
        this->iSize[0] = width;
        this->iSize[1] = height;
        this->std::vector<T>::resize(width * height);
    };

    T& operator()(int row, int col) {
        return (*this)[row * this->iSize[0] + col];
    };

    /*void setValue(int row, int col, T value) {
        (*this)[row * this->iSize[0] + col] = value;
    }
    ;
    T getValue(int row, int col) {
        return (*this)[row * this->iSize[0] + col];
    };*/
};