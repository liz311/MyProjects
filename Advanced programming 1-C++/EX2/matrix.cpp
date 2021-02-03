/* Created By Lizzy Asis */

#include "Matrix.h"


//Constructor that gets rows and columns and defines the variables inside the class, also builds matrix at this size.
//Used as default constractor as well.
Matrix::Matrix(int Rows,int Columns)
{
	Set_Rows(Rows);
	Set_Columns(Columns);
	Two_Dimensional_Array = new int*[Rows];
	for (int i=0;i<Rows;i++)
		Two_Dimensional_Array[i] = new int[Columns];
	for (int i=0;i<Rows;i++)
		for (int j=0;j<Columns;j++)
			Two_Dimensional_Array[i][j] = 0;
}

//Constructor that gets another object from same type and makes exactly the same one.
Matrix::Matrix(const Matrix &ToCopyFrom)
{
	Set_Rows(ToCopyFrom.Get_Rows());
	Set_Columns(ToCopyFrom.Get_Columns());
	Two_Dimensional_Array = new int*[Rows];
	for (int i=0;i<Rows;i++)
		Two_Dimensional_Array[i] = new int[Columns];
	for (int i=0;i<Rows;i++)
		for (int j=0;j<Columns;j++)
			Two_Dimensional_Array[i][j] = ToCopyFrom.Two_Dimensional_Array[i][j];
}

//Destructors
Matrix::~Matrix()
{
	for (int i=0;i<Rows;i++)
		delete[] Two_Dimensional_Array[i];
	delete[] Two_Dimensional_Array;
}

//Function that returns rows value.
int Matrix::Get_Rows() const {return Rows;}

//Function that returns columns value.
int Matrix::Get_Columns() const{return Columns;}

//Function that gets value and set it inside his class.
void Matrix::Set_Rows(int Rows) {this->Rows = Rows;}

//Function that gets value and set it inside his class.
void Matrix::Set_Columns(int Columns) {this->Columns = Columns;}

//Operator that gets same object type and copy it to motivating factor.
const Matrix &Matrix::operator=(const Matrix &ToCopyFrom)
{
	//Checks if one of the operators *,+,- was illegaly used, so it will return what was at left side of 'operator'.
	if ((ToCopyFrom.Get_Rows() == 0)&&(ToCopyFrom.Get_Columns() == 0))
		return *this;
	//You can keep look at the code without being afraid of it :)
	if (this != &ToCopyFrom)
	{
		if((ToCopyFrom.Columns != Columns)&&(ToCopyFrom.Rows != Rows))
		{
			for (int i=0;i<Rows;i++)
				delete [] Two_Dimensional_Array[i];
			delete [] Two_Dimensional_Array;
			Set_Rows(ToCopyFrom.Get_Rows());
			Set_Columns(ToCopyFrom.Get_Columns());
			Two_Dimensional_Array = new int*[Rows];
			for (int i=0;i<Rows;i++)
				Two_Dimensional_Array[i] = new int[Columns];
		}
		for (int i=0;i<Rows;i++)
			for (int j=0;j<Columns;j++)
				Two_Dimensional_Array[i][j] = ToCopyFrom.Two_Dimensional_Array[i][j];
	}
	return *this;
}

//Checks if motivating factor and the object that he gets are the same.
bool Matrix::operator==(const Matrix &ToCheckOn) const
{
	if ((Rows != ToCheckOn.Rows)&&(Columns != ToCheckOn.Columns))
		return false;
	for (int i=0;i<Get_Rows();i++)
		for (int j=0;j<Get_Columns();j++)
			if (Two_Dimensional_Array[i][j] != ToCheckOn.Two_Dimensional_Array[i][j])
				return false;
	return true;
}

//Checks if motivating factor and the object that he gets are the NOT the same.
bool Matrix::operator!=(const Matrix &ToCheckOn) const {return !(*this == ToCheckOn);}

//Motivating factor is multiplied by a number that is getting in function and we call him "Constant_Number".
const Matrix Matrix::operator*(int Constant_Number) const
{
	Matrix New_Matrix = *this;
	for (int i=0;i<New_Matrix.Get_Rows();i++)
		for (int j=0;j<New_Matrix.Get_Columns();j++)
			New_Matrix.Two_Dimensional_Array[i][j] *= Constant_Number;
	return New_Matrix;
}

//Ostream function that display on screen the matrix it self.
ostream &operator<<(ostream &Output,const Matrix &Current_Matrix)
{
	for (int i=0;i<Current_Matrix.Get_Rows();i++)
	{
		for (int j=0;j<Current_Matrix.Get_Columns();j++)
		{
			Output<<Current_Matrix[i][j]<<"   ";
		}
		Output<<endl<<endl;
	}
	return Output;
}

//Function that is constant number multiplied by a matrix, this is also a friend fnuction.
const Matrix operator*(int Constant_Number,const Matrix &ToWorkWith) {return ToWorkWith * Constant_Number;}

//Motivating factor is getting multiplied by '-1'.
const Matrix Matrix::operator-() const
{
	Matrix New_Matrix = *this;
	New_Matrix = New_Matrix * (-1);
	return New_Matrix;
}

//Function that adds motivating factor and a object that gets in function with him. 
const Matrix Matrix::operator+(const Matrix &Second_Matrix) const
{
	if ((Rows != Second_Matrix.Get_Rows())&&(Columns != Second_Matrix.Get_Columns()))
	{
		cout<<"Adding between two matrices failed due to incorrect data.\n";
		return Matrix(0 , 0);//Returns it and at '=' it will get back to original Matrix without fails.
	}
	Matrix New_Matrix = *this;
	for (int i=0;i<Rows;i++)
		for (int j=0;j<Columns;j++)
			New_Matrix.Two_Dimensional_Array[i][j] += Second_Matrix.Two_Dimensional_Array[i][j];
	return New_Matrix;
}

//Function that subtract motivating factor and a object that gets in function with him. 
const Matrix Matrix::operator-(const Matrix &Second_Matrix) const
{
	if ((Rows != Second_Matrix.Get_Rows())&&(Columns != Second_Matrix.Get_Columns()))
	{
		cout<<"Subtraction matrices failed due to incorrect data.\n";
		return Matrix(0 , 0);//Returns it and at '=' it will get back to original Matrix without fails.
	}
	Matrix New_Matrix = *this;
	for (int i=0;i<Rows;i++)
		for (int j=0;j<Columns;j++)
			New_Matrix.Two_Dimensional_Array[i][j] -= Second_Matrix.Two_Dimensional_Array[i][j];
	return New_Matrix;
}

//Function that multiply motivating factor and the object that gets with him in the function.
const Matrix Matrix::operator*(const Matrix &Second_Matrix) const
{
	if (Columns != Second_Matrix.Get_Rows())
	{
		printf ("Multiplying matrices failed due to incorrect data.\n");
		return Matrix(0 , 0);//Returns it and at '=' it will get back to original Matrix without fails.
	}
	Matrix New_Matrix(Rows,Second_Matrix.Get_Columns());
	for (int i=0;i<Rows;i++)
	{
		for (int j=0;j<Second_Matrix.Columns;j++)
		{
			New_Matrix.Two_Dimensional_Array[i][j] = 0;
			for (int k=0;k<Columns;k++)
				New_Matrix.Two_Dimensional_Array[i][j] += (Two_Dimensional_Array[i][k]) * (Second_Matrix.Two_Dimensional_Array[k][j]);
		}
	}
	return New_Matrix;
}

//Function that returns an array and acts exactly as Arr[x], and Arr is **
int *Matrix::operator[] (int Location) {return Two_Dimensional_Array[Location];}

const int *Matrix::operator[](int Location) const {return Two_Dimensional_Array[Location];}
