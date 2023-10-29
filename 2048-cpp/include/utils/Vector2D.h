#pragma once

#include <vector>
#include "Vector2D.h"
#include "../../data/globals.h"

template <typename T>
class Vector2D : public std::vector<T>
{
private:
	int sizes[2];

public:
    
    
    Vector2D(int size) : std::vector<T>(size * size) {
        this->sizes[0] = size;
        this->sizes[1] = size;
    };

    Vector2D(int width, int height) : std::vector<T>(width* height) {
        this->sizes[0] = width;
        this->sizes[1] = height;
    };

    int calculateCursor(int row, int col) {
		return row * this->sizes[0] + col;
	};

    int getSingleSize(int lengthIndex) {
        return this->sizes[lengthIndex];
    };

    void resize(int size) {
        this->resize(size, size);
    };
    void resize(int width, int height) {
        this->sizes[0] = width;
        this->sizes[1] = height;
        this->std::vector<T>::resize(width * height);
    };

    T& operator()(int row, int col) {
        return (*this)[row * this->sizes[0] + col];
    };

    /*void setValue(int row, int col, T value) {
        (*this)[row * this->sizes[0] + col] = value;
    }
    ;
    T getValue(int row, int col) {
        return (*this)[row * this->sizes[0] + col];
    };*/
};