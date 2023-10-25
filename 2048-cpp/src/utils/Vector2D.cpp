#include "../../include/utils/Vector2D.h"

template<typename T>
Vector2D<T>::Vector2D(int size)
{
	this->size[0] = size;
	this->size[1] = size;
}

template<typename T>
Vector2D<T>::Vector2D(int width, int height)
{
	this->size[0] = width;
	this->size[1] = height;
}

template<typename T>
Vector2D<T>::~Vector2D()
{
}

template<typename T>
int Vector2D<T>::getSize()
{
	return this->size[0] * this->size[1];
}

template<typename T>
void Vector2D<T>::resize(int size)
{
	this->resize(size, size);
}

template<typename T>
void Vector2D<T>::resize(int width, int height)
{
	this->size[0] = width;
	this->size[1] = height;
	std::vector<T>::resize(width * height);
}

template<typename T>
T& Vector2D<T>::operator[](int index[2])
{
	return this[index[0]*this->size[0] + index[2]];
}

template<typename T>
void Vector2D<T>::setValue(int index[2], T value)
{
	this[index[0] * this->size[0] + index[2]] = value;
}

template<typename T>
T Vector2D<T>::getValue(int index[2])
{
	return this[index[0] * this->size[0] + index[2]];
}