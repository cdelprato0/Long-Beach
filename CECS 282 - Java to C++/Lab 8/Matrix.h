//Chaz Del Prato
//Lab 8
//CECS 282
#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <cassert>
using namespace std;

class Matrix{
private:
	int rows;
	int cols;
	int **M;

public:
	Matrix(const int &rows, const int &cols);
	Matrix(const Matrix &other);
	~Matrix();
	int* & operator[](const int &index) const;
	void operator=(const Matrix &other);
	Matrix operator -()const;
	Matrix operator -(const Matrix &other)const;
	Matrix operator +(const Matrix &other)const;
	Matrix operator *(const Matrix &other)const;
	Matrix operator *(const int &num)const;
	Matrix operator++();
	Matrix operator--();
	int getMatrixRows();
	int getMatrixCols();
	friend Matrix operator *(const int & num, const Matrix &m);
	friend Matrix operator +(const int &num, const Matrix &t);
	friend ostream &operator<<(ostream &os, const Matrix &m);
	friend istream& operator>> (istream& in, const Matrix& m);
};

#endif /* MATRIX_H_ */

