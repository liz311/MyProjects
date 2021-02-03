/* Created By Lizzy Asis */

#ifndef MATRIX_HEADER
#define MATRIX_HEADER

#include <iostream>
using namespace std;

class Matrix
{
	friend ostream &operator<<(ostream &,const Matrix &);
	friend const Matrix operator*(int,const Matrix &);
private:
	int **Two_Dimensional_Array ;
	int Rows, Columns;
public:
	Matrix(int =0,int =0);
	Matrix(const Matrix &);
	~Matrix();

	int Get_Rows() const;
	int Get_Columns() const;
	void Set_Rows(int);
	void Set_Columns(int);

	const Matrix &operator=(const Matrix &);
	bool operator==(const Matrix &) const;
	bool operator!=(const Matrix &) const;
	int *operator[](int);
	const int *operator[](int) const;

	const Matrix operator*(int) const;
	const Matrix operator*(const Matrix &) const;
	const Matrix operator+(const Matrix &) const;
	const Matrix operator-(const Matrix &) const;
	const Matrix operator-() const;
};
#endif
