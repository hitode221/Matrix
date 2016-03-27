#pragma once
#include <fstream>
#include <iostream>

class Matrix {
public:
	Matrix() : lines(0), columns(0), elements(nullptr) {}
	Matrix(int _lines, int _columns);
	Matrix(const Matrix& second);
	Matrix& operator= (const Matrix& second);
	void swapMatrix (Matrix& second);
	void fillRandom();
	void fill(char *filename);
	void print() const;
	int* operator[](int index) const;
	Matrix operator+(const Matrix& m) const; 
	Matrix operator*(const Matrix& m) const; 
	int getLines() const;
	int getColumns() const;
	~Matrix();
private:
	int lines, columns, **elements;
};