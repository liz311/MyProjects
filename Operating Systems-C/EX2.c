/* Created By Lizzy Asis */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


#define FIRST_MATRIX_ROWS 3
#define FIRST_MATRIX_COLUMNS 4//Must be equal to 'SECOND_MATRIX_ROWS'.
#define SECOND_MATRIX_ROWS 4//Must be equal to 'FIRST_MATRIX_COLUMNS'.
#define SECOND_MATRIX_COLUMNS 2

typedef struct threeFieldData
{
	int Data;
	int IIndex;
	int JIndex;
}threeFieldData;

typedef struct Node
{
	threeFieldData data;
	struct Node *next;
}Node;

typedef struct List
{
	int size;
	Node *head, *tail;
}List;

// General Declaration - Start
void menu();
// General Declaration - End

// Ex1 - Declaration start
void Ex1();
void printArray(int* arr, int size);
int *pow(int size);
// Ex1 - Declaration end


// Ex2 - Declaration start
void Ex2();
void FirstMatrixRandomInsertValues(int FirstMatrix[][FIRST_MATRIX_COLUMNS], int Rows, int Columns);
void SecondMatrixRandomInsertValues(int SecondMatrix[][SECOND_MATRIX_COLUMNS], int Rows, int Columns);
int **DeclareOnMatrixMultiplication(int Rows, int Columns);
void MultiplicationFunction(int **ArrayMult, int Matrix1[][FIRST_MATRIX_COLUMNS], int r1, int c1, int Matrix2[][SECOND_MATRIX_COLUMNS], int r2, int c2);
void DisplayMatrix(int **Array, int Rows, int Columns);
void FirstMatrixDisplayValues(int FirstMatrix[][FIRST_MATRIX_COLUMNS], int Rows, int Columns);
void SecondMatrixDisplayValues(int SecondMatrix[][SECOND_MATRIX_COLUMNS], int Rows, int Columns);
void FreeMemoryOfMatrix(int **Matrix, int Rows);
// Ex2 - Declaration end

// Ex3 - Declaration start
void Ex3();
int **createMatrix (int *rows, int *columns);
void DisplayArray (threeFieldData *arr, int counter);
void Add(List *myList, int data, int i, int j);
void init(List *myList);
void DisplayList(List *myList);
// Ex3 - Declaration end

void main()
{
	//Variables daclaration
	int select;
	menu();
	scanf("%d", &select);
	while (select != 4)
	{
		switch (select)
		{
		case 1:
			Ex1();
			break;
		case 2:
			Ex2();
			break;
		case 3:
			Ex3();
			break;
		}
		printf("What do you want to do: ");
		scanf("%d", &select);
	}
}

void menu()
{
	printf("I am Lizzy PRO DEVELOPER\n");
	printf("1. First program\n2. Second program\n3. Third program\nYour choice: ");
}

// Ex1 - Functions start
void Ex1()
{
	int* p, size;

	printf("Enter your size: ");
	scanf("%d", &size);

	while (size < 1 || size > 32)
	{
		printf("Bad input. Try again: ");
		scanf("%d", &size);
	}

	p = pow(size);
	printArray(p, size);
	free(p);
}

int* pow(int size)
{
	int *P,i;

	P = (int*)malloc(size * sizeof(int));
	P[0] = 1;

	for (i = 1; i < size; i++)
		P[i] = P[i - 1] * 2;
	return P;
}

void printArray(int *arr, int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
// Ex1 - Functions end

//Ex1 - Declaration start

void Ex2();
void FirstMatrixRandomInsertValues(int FirstMatrix[][FIRST_MATRIX_COLUMNS], int Rows, int Columns);
void SecondMatrixRandomInsertValues(int SecondMatrix[][SECOND_MATRIX_COLUMNS], int Rows, int Columns);
int **DeclareOnMatrixMultiplication(int Rows, int Columns);
void MultiplicationFunction(int **ArrayMult, int Matrix1[][FIRST_MATRIX_COLUMNS], int r1, int c1, int Matrix2[][SECOND_MATRIX_COLUMNS], int r2, int c2);
void DisplayMatrix(int **Array, int Rows, int Columns);
void FirstMatrixDisplayValues(int FirstMatrix[][FIRST_MATRIX_COLUMNS], int Rows, int Columns);
void SecondMatrixDisplayValues(int SecondMatrix[][SECOND_MATRIX_COLUMNS], int Rows, int Columns);
void FreeMemoryOfMatrix(int **Matrix, int Rows);


void Ex2()
{
	int **ArrayMult, FirstMatrix[FIRST_MATRIX_ROWS][FIRST_MATRIX_COLUMNS], SecondMatrix[SECOND_MATRIX_ROWS][SECOND_MATRIX_COLUMNS];//Second function.
	printf("The funcation running on random number mode.\n");
	FirstMatrixRandomInsertValues(FirstMatrix, FIRST_MATRIX_ROWS, FIRST_MATRIX_COLUMNS);
	SecondMatrixRandomInsertValues(SecondMatrix, SECOND_MATRIX_ROWS, SECOND_MATRIX_COLUMNS);
	ArrayMult = DeclareOnMatrixMultiplication(FIRST_MATRIX_ROWS, SECOND_MATRIX_COLUMNS);
	MultiplicationFunction(ArrayMult, FirstMatrix, FIRST_MATRIX_ROWS, FIRST_MATRIX_COLUMNS, SecondMatrix, SECOND_MATRIX_ROWS, SECOND_MATRIX_COLUMNS);
	FirstMatrixDisplayValues(FirstMatrix, FIRST_MATRIX_ROWS, FIRST_MATRIX_COLUMNS);
	SecondMatrixDisplayValues(SecondMatrix, SECOND_MATRIX_ROWS, SECOND_MATRIX_COLUMNS);

	printf("Multiplication matrix: \n");
	DisplayMatrix(ArrayMult, FIRST_MATRIX_ROWS, SECOND_MATRIX_COLUMNS);
	FreeMemoryOfMatrix(ArrayMult, FIRST_MATRIX_ROWS);
}
//Inputs random values into the static matrix.
void FirstMatrixRandomInsertValues(int FirstMatrix[][FIRST_MATRIX_COLUMNS], int Rows, int Columns)
{
	int i, j;
	srand(time(NULL));
	for (i = 0; i < Rows; i++)
		for (j = 0; j < Columns; j++)
			FirstMatrix[i][j] = 1 + rand() % 9;
}
void SecondMatrixRandomInsertValues(int SecondMatrix[][SECOND_MATRIX_COLUMNS], int Rows, int Columns)
{
	int i, j;
	srand(time(NULL));
	for (i = 0; i < Rows; i++)
		for (j = 0; j < Columns; j++)
			SecondMatrix[i][j] = 1 + rand() % 9;
}
//Funcation gets rows and columns length, creates dynamic matrix, and returns his address.
int **DeclareOnMatrixMultiplication(int Rows, int Columns)
{
	int **Array, i;
	Array = (int**)malloc(Rows * sizeof(int*));
	for (i = 0; i < Rows; i++)
		Array[i] = (int*)malloc(Columns * sizeof(int));
	return Array;
}
//The funcation gets two matrixs and the dynamic matrix and multiplicate it.
void MultiplicationFunction(int **ArrayMult, int Matrix1[][FIRST_MATRIX_COLUMNS], int r1, int c1, int Matrix2[][SECOND_MATRIX_COLUMNS], int r2, int c2)
{
	//ArrayMuly will be used only with 'c1' and 'r2' since they are the 'mxp' as requested.
	int i, j, k;
	if (c1 != r2)
	{
		printf("You can not perform the operation because the necessary data does not exist.\n");
		return;
	}
	for (i = 0; i < r1; ++i)
	{
		for (j = 0; j < c2; ++j)
		{
			ArrayMult[i][j] = 0;
			for (k = 0; k < c1; ++k)
				ArrayMult[i][j] += Matrix1[i][k] * Matrix2[k][j];
		}
	}
}
//Fucation display the values of the matrix.
void FirstMatrixDisplayValues(int FirstMatrix[][FIRST_MATRIX_COLUMNS], int Rows, int Columns)
{
	int i, j;
	printf("\nThe first matrix display.\n");
	for (i = 0; i < Rows; i++)
	{
		for (j = 0; j < Columns; j++)
			printf("%d   ", FirstMatrix[i][j]);
		printf("\n\n");
	}
	printf("\n");
}
void SecondMatrixDisplayValues(int SecondMatrix[][SECOND_MATRIX_COLUMNS], int Rows, int Columns)
{
	int i, j;
	printf("The second matrix display.\n");
	for (i = 0; i < Rows; i++)
	{
		for (j = 0; j < Columns; j++)
			printf("%d   ", SecondMatrix[i][j]);
		printf("\n\n");
	}
	printf("\n");
}
void DisplayMatrix(int **Array, int Rows, int Columns)
{
	int i, j;
	for (i = 0; i < Rows; i++)
	{
		for (j = 0; j < Columns; j++)
		{
			printf("%d   ", Array[i][j]);
			if (j == Columns - 1)
				printf("\n\n");
		}
		//printf ("\n\n");
	}
}
//Funcation gets the dynamic matrix and free it.
void FreeMemoryOfMatrix(int **Matrix, int Rows)
{
	int i;
	for (i = 0; i < Rows; i++)
		free(Matrix[i]);
	free(Matrix);
}

// Ex3
void Ex3()
{
	int **Matrix, rows, columns, i, j, counter;
	threeFieldData *arrayOfThree;
	List myList;

	init(&myList);
	counter = 0;

	Matrix = createMatrix(&rows, &columns);

	for(i=0 ; i<rows ; i++)
		for(j=0 ; j<columns ; j++)
			if(i+j == Matrix[i][j])
				counter++;

	arrayOfThree = (threeFieldData*)malloc(counter * sizeof(threeFieldData));
	counter = 0;
	for(i=0 ; i<rows ; i++)
	{
		for(j=0 ; j<columns ; j++)
		{
			if(i+j == Matrix[i][j])
			{
				arrayOfThree[counter].Data = Matrix[i][j];
				arrayOfThree[counter].IIndex = i;
				arrayOfThree[counter].JIndex = j;
				counter++;
				Add(&myList, Matrix[i][j], i, j);
			}
		}
	}
	printf("The array: \n");
	DisplayArray(arrayOfThree, counter);
	printf("The list: \n");
	DisplayList(&myList);
}

int **createMatrix (int *rows, int *columns)
{
	int **Matrix, i, j;

	printf("Lizzy's rows: ");
	scanf("%d",rows);
	printf("Lizzy's columns: ");
	scanf("%d",columns);

	Matrix = (int**)malloc(*rows * sizeof(int*));

	for (i = 0; i < *rows; i++)
	{
		Matrix[i] = (int*)malloc(*columns * sizeof(int));
	}

	for (i = 0; i < *rows; i++)
	{
		for (j = 0; j < *columns; j++)
		{
			printf("[%d][%d] ",i,j);
			scanf ("%d", &Matrix[i][j]);
		}
	}
	return Matrix;
}
void DisplayArray (threeFieldData *arr, int counter)
{
	int i;

	for (i = 0; i < counter; i++)
		printf ("%d %d %d\n", arr[i].Data, arr[i].IIndex, arr[i].JIndex);
	printf("\n");
}
void init(List *myList)
{
	myList->head = NULL;
	myList->tail = NULL;
	myList->size = 0;
}
void Add(List *myList, int data, int i, int j)
{
	if(myList->head == NULL)
	{
		myList->head = (Node*)malloc(sizeof(Node));
		myList->tail = myList->head;
	}
	else
	{
		myList->tail->next = (Node*)malloc(sizeof(Node));
		myList->tail = myList->tail->next;
	}
	myList->tail->data.Data = data;
	myList->tail->data.IIndex = i;
	myList->tail->data.JIndex = j;
	myList->tail->next = NULL;
	myList->size = myList->size + 1;
}
void DisplayList(List *myList)
{
	Node *Current;
	Current = myList->head;

	while(Current != NULL)
	{
		printf("%d %d %d\n",Current->data.Data, Current->data.IIndex, Current->data.JIndex);
		Current = Current->next;
	}
	printf("\n");
}
