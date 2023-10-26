#include "../../data/globals.h"
#include "../../include/utils/Vector2D.h"

template<typename T>
Vector2D<T>::Vector2D(int size) : std::vector<T>(size * size) {
    this->iSize[0] = size;
    this->iSize[1] = size;
};

template<typename T>
Vector2D<T>::Vector2D(int width, int height) : std::vector<T>(width * height) {
    this->iSize[0] = width;
    this->iSize[1] = height;
};

template<typename T>
int Vector2D<T>::getSingleSize(GridDimension lengthIndex) {
	return this->iSize[lengthIndex];
};

template<typename T>
void Vector2D<T>::resize(int size) {
    this->resize(size, size);
};

template<typename T>
void Vector2D<T>::resize(int width, int height) {
    this->iSize[0] = width;
    this->iSize[1] = height;
    this->std::vector<T>::resize(width * height);
};



template<typename T>
T& Vector2D<T>::operator()(int row, int col) {
    return (*this)[row * this->iSize[0] + col];
};

template<typename T>
T Vector2D<T>::getValue(int row, int col) {
	return (*this)[row * this->iSize[0] + col];
};

template<typename T>
void Vector2D<T>::setValue(int row, int col, T value) {
    (*this)[row * this->iSize[0] + col] = value;
};

