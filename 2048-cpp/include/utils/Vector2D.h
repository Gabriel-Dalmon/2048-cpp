#pragma once

#include <vector>
#include <iostream>

template <typename T>
class Vector2D : public std::vector<T>
{
public:
	int size[2]; // [0] = width, [1] = height

	Vector2D(int size);
	Vector2D(int width, int height);
	~Vector2D();

	int getSize();
	void resize(int size);
	void resize(int width, int height);

	T& operator[](int index);
	T& operator[](int index[2]);

	void setValue(int index[2], T value);
	T getValue(int index[2]);

private:

};
