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
    inline Vector2D(int size) : std::vector<T>(size * size) {
        this->sizes[0] = size;
        this->sizes[1] = size;
    };

    inline Vector2D(int width, int height) : std::vector<T>(width* height) {
        this->sizes[0] = width;
        this->sizes[1] = height;
    };

    inline int calculateCursor(int row, int col) {
		return row * this->sizes[0] + col;
	};

    inline int getSingleSize(int lengthIndex) {
        return this->sizes[lengthIndex];
    };

    inline void resize(int size) {
        this->resize(size, size);
    };
    inline void resize(int width, int height) {
        this->sizes[0] = width;
        this->sizes[1] = height;
        this->std::vector<T>::resize(width * height);
    };

    inline T& operator()(int row, int col) {
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