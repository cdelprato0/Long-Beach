//Chaz Del Prato
//Lab 8
//CECS 282
#include "Matrix.h"

Matrix::Matrix(const int &row, const int &col) {
	rows = row;
	cols = col;
	M = new int *[row];
	assert(M);

	for(int i = 0; i < rows; i++){
		M[i] = new int[cols];
		assert(M[i]);
	}

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			M[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix &other){
	cols = other.cols;
	rows = other.rows;
	M = new int *[other.rows];
	assert(M);

	for(int i = 0; i < other.rows; i++){
		M[i] = new int[other.cols];
		assert(M[i]);
	}

	for(int i = 0; i < other.rows; i++){
		for(int j = 0; j < other.cols; j++){
			M[i][j] = other[i][j];
		}
	}
}

Matrix::~Matrix() {
	for(int i = 0; i < rows; i++){
		delete [] M[i];
	}
	delete [] M;
}


int* & Matrix::operator[](const int &index) const{
	return M[index];
}

void Matrix::operator=(const Matrix &other){
	if(M != other.M && cols == other.cols && rows == other.rows){
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				M[i][j] = other.M[i][j];
			}
		}
	}
}

Matrix Matrix::operator -()const{
	Matrix temp(rows, cols);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			temp.M[i][j] = M[i][j] * - 1;
		}
	}
	return temp;
}

Matrix Matrix::operator -(const Matrix &other)const{
	Matrix temp(rows, cols);

	if(rows != other.rows || cols != other.cols){

		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				temp.M[i][j] = M[i][j];
			}
		}
		return temp;
	}else{
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				temp.M[i][j] += other.M[i][j] - M[i][j];
			}
		}
		return temp;
	}
}
Matrix Matrix::operator +(const Matrix &other)const{
	Matrix temp(rows, cols);

	if(rows != other.rows || cols != other.cols){

		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				temp.M[i][j] = M[i][j];
			}
		}
		return temp;
	}else{
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				temp.M[i][j] += other.M[i][j] + M[i][j];
			}
		}
		return temp;
	}
}

Matrix Matrix::operator *(const Matrix &other)const{
	if(cols != other.rows){
		Matrix temp(cols, rows);

		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				temp.M[i][j] = M[i][j];
			}
		}
		return temp;
	}else{
		Matrix temp(cols, other.rows);

		for(int i = 0; i < rows; i++){
			for(int j = 0; j < other.cols; j++){
				for(int k = 0; k < cols; k++){
					temp[i][j] += M[i][k] * other.M[i][j];
				}
			}
		}
		return temp;
	}
}

Matrix Matrix::operator *(const int &num)const{
	Matrix temp(rows, cols);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; i++){
			temp.M[i][j] = M[i][j] * num;
		}
	}
	return temp;
}

Matrix Matrix::operator++(){
	Matrix temp(rows, cols);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; i++){
			temp.M[i][j] = ++M[i][j];
		}
	}
	return temp;
}

Matrix Matrix::operator--(){
	Matrix temp(rows, cols);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; i++){
			temp.M[i][j] = M[i][j]--;
		}
	}
	return temp;
}

int Matrix::getMatrixRows(){
	return rows;
}
int Matrix::getMatrixCols(){
	return cols;
}

Matrix operator *(const int & num, const Matrix &m){
	return (m * num);
}
Matrix operator +(const int &num, const Matrix &t){
	
	for(int i = 0; i < t.rows; i++){
		for(int j = 0; j < t.cols; i++){
			t.M[i][j] += num;
		}
	}
	return t;	
}

ostream &operator<<(ostream &os, const Matrix &m){
	for(int i = 0; i < m.rows ; i++){
		for(int j = 0; j < m.cols; j++){
			os << m.M[i][j];
		}
	}
	return os;
}

istream& operator>> (istream& in, const Matrix& m){
	
	for(int i = 0; i < m.rows ; i++){
		for(int j = 0; j < m.cols; j++){
			in >> m.M[i][j];
		}
	}
	return in;
}


