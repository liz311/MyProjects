#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include<math.h>
#include <conio.h>

/* Created By Lizzy Asis */

void Ex1();
void OddEven(int *Array, int length);
void Swap(int *First, int *Second);
void ShowOfArray(int *Array, int length);
int *ArrayCreation(int *length);
void Ex2();
int getSumOfDigit(int num);
int couldBeDividedBy11(int num);
void Ex3();
void PrintArray(int *arr, int length);
int* InputArrayDyn(int n);
void MergeSort(int *a, int first, int last);
void Merge(int *a, int p, int q, int r);
int* MergeArrays(int *a, int *b, int n, int m, int *k);
void Ex4();
int first_solution(int first_array[], int second_array[], int array_length);
int second_solution(int first_array[], int second_array[], int array_length);
int* narrow_array(int array_to_change[], int place, int array_length);
int third_solution(int first_array[], int second_array[], int array_length);
void Ex5();
void remove_letter(char *Str, char ch);
char *Create_new_string();

void main()
{
	menu();
}

int menu() // פונקציה המאחדת את כל התרגילים
{
	int select = 1;

	while (select)
	{
		printf("Ex1--->1\n");
		printf("Ex2--->2\n");
		printf("Ex3--->3\n");
		printf("Ex4--->4\n");
		printf("Ex4--->5\n");
		printf("EXIT-->0\n");

		do
		{
			printf("please select 0-5 : ");
			scanf("%d", &select);

		} while ((select<0) || (select>5));

		switch (select)
		{
		case 1: Ex1();
			break;
		case 2: Ex2();
			break;
		case 3: Ex3();
			break;
		case 4: Ex4();
			break;
		case 5: Ex5();
			break;

		case 0: printf("Good bye!\n");
		}
	}
}

// ***** Ex1 *****
void Ex1()
{
	int *Array, length;
	Array = ArrayCreation(&length);
	ShowOfArray(Array, length);
	OddEven(Array, length);
	ShowOfArray(Array, length);
	free(Array);
}
int *ArrayCreation(int *length)//יצירה של מערך חדש
{
	int *Array, i;
	printf ("Please enter array size: ");
	scanf ("%d", length);
	Array = (int*)malloc((*length)*sizeof(int));
	for (i=0 ; i<(*length) ; i++)
	{
		printf ("Enter %d value in array: ", i);
		scanf ("%d" , &Array[i]);
	}
	return Array;
}

void Swap(int *First, int *Second)//החלפת מיקומם של המשתנים במערך
{
	int Temp = *First;
	*First = *Second;
	*Second = Temp;
}

void ShowOfArray(int *Array, int length)//הצגה של מערך
{
	int i;
	for (i=0 ; i<length ; i++)
		printf ("[%d] ", Array[i]);
	printf ("\n\n");
}

void OddEven(int *Array, int length)// בדיקה של משתנים- זוגי או אי זוגי
{
	int Left, Right;
	Left = 0;
	Right = length - 1;
	while (Left < Right)
	{
		while (((Array[Left]%2) != 0) && (Left < Right))
			Left++;

		while (((Array[Right]%2) == 0) && (Left < Right))
			Right--;

		if (Left < Right)
		{
			Swap(&Array[Left], &Array[Right]);
			Left++;
			Right--;
		}
	}
}



// ***** Ex2 *****

void Ex2()
{
	int num;
	printf("Enter a number \n");
	scanf_s("%d", &num);
	printf("Sum of digits of %d is %d. \n", num, getSumOfDigit(num));

	if (couldBeDividedBy11(num))
		printf("The number %d could be divided by eleven. \n", num);

	else
		printf("The number %d could not be divided by eleven. \n", num);
}

/*
* פונקציה לחישוב סכום הספרות של מספר
*/
int getSumOfDigit(int num){
	/*רקורסיה למצב סיום*/
	if (num == 0)
		return 0;

	return (num % 10) - getSumOfDigit(num / 10);
}

/*
* פונקציה המחשבת מספר ובודקת אם הוא מתחלק ב-11
*/
int couldBeDividedBy11(int num){
	int theSum;
	theSum = getSumOfDigit(num);
	while ((theSum < -10) || (10 < theSum))
	{
        num = theSum;
		theSum = getSumOfDigit(num);
	}
	return (theSum == 0);
}


// ***** Ex3 *****
void Ex3()
{
	int n, m, k;//מספרים שלמים המייצגים את אורך המערך
	int *arrA, *arrB, *arrC;//הכרזה על מצביעי מערכים
	printf("Enter size of your first array\n");
	scanf_s("%d", &n);//מקבל את גודל המערך הראשון
	arrA = InputArrayDyn(n);//מקבל את המערך הראשון
	printf("Enter size of your second array\n");
	scanf_s("%d", &m);//מקבל את גודל המערך השני
	arrB = InputArrayDyn(m);//מקבל את המערך השני
	MergeSort(arrA, 0, n - 1);//מיון המערך הראשון
	PrintArray(arrA, n);//מדפיס את המערך הראשון לאחר מיון
	MergeSort(arrB, 0, m - 1);//מיון המערך השני
	PrintArray(arrB, m);//מדפיס את המערך השני לאחר מיון
	arrC = MergeArrays(arrA, arrB, n, m, &k);//מיזוג מספרים שווים לתוך מערך חדש
	printf("New Array: ");
	PrintArray(arrC, k);//הדפסת המערך החדש
	free(arrA);//שיחרור של זיכרון המערך
	free(arrB);
	free(arrC);
}
//הדפסת מערך נתון
void PrintArray(int *arr, int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//קבלת מערך דינמי מהמשתמש
int* InputArrayDyn(int n)
{
	int i;//אינדקס
	int *a;//מצביע של מערך
	a = (int *)calloc(n, sizeof(int));//הקצאה דינמית של זיכרון
	assert(a); /* calloc() worked */
	printf("Enter array of length %d\n", n);
	for (i = 0; i < n; i++)
		scanf_s("%d", a + i);
	return a;
}

void MergeSort(int *array, int first, int last)
{
	int middle;
	if (first < last)
	{
		middle = (first + last) / 2;//חיתוך המערך לחצי
		MergeSort(array, first, middle);//רקורסיה
		MergeSort(array, middle + 1, last);//רקורסיה
		Merge(array, first, middle, last);//מיזוג המערך הממוין
	}
}
//מיזוג המספרים המופרדים לאחר פעולה רקורסיבית של מיון ומיזוג
void Merge(int *array, int first, int middle, int last)
{
	int i = first, j = middle + 1, k = 0;
	int* temp = (int*)calloc(last - first + 1, sizeof(int));//הקצאה דינמית של זיכרון
	while ((i <= middle) && (j <= last))
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	while (j <= last) // if( i>q )
		temp[k++] = array[j++];
	while (i <= middle) // j>r
		temp[k++] = array[i++];
	for (i = first, k = 0; i <= last; i++, k++)
		array[i] = temp[k];
	free(temp);//שיחרור זיכרון
}

//מיזוג את שני מערכים ממוינים לתוך מערך אחד עם מספרים שווים
int* MergeArrays(int *arrA, int *arrB, int n, int m, int *arrayLength)
{
	int *temp = (int*)malloc((n + m)*sizeof(int));//הקצאה דינמית של זיכרון
	int i = 0, j = 0, k = 0, newArrayLength = 0;
	while (i < n && j < m)
	{
		if (arrA[i] == arrB[j])//בדיקה אם שווים
		{
			temp[k++] = arrA[i++];
			j++;
			newArrayLength++;
		}
		else
		{
			if (arrA[i] < arrB[j])
			{
				i++;
			}
			else
			{
				j++;
			}
		}
	}
	*arrayLength = newArrayLength;//אורך חדש
	return temp;//מחזיר את המערך החדש
}



// ***** Ex4 *****
void Ex4() 
{
	int n;//מספרים שלמים המייצגים את אורך המערכים // 
	int *arrA, *arrB;//הכרזה על מצביעי מערכים

	printf("Enter size of the two arrays\n");
	scanf("%d", &n);//מקבל את גודל המערך השני

	// printf("Enter size of your first array\n");
	// scanf("%d", &m);//מקבל את גודל המערך הראשון

	arrA = InputArrayDyn(n); // מקבל את המערך הראשון
	// printf("Enter size of your second array\n");
	// scanf("%d", &n);//מקבל את גודל המערך השני
	arrB = InputArrayDyn(n); // מקבל את המערך השני


	printf("They are similar by the \n");

	printf("Third solution: ");
	if (third_solution(arrA, arrB, n)) {
		printf("Yes. \n");
	} else {
		printf("No. \n");
	}
	printf("A Array: ");
	PrintArray(arrA, n);//הדפסת המערך החדש
	printf("B Array: ");
	PrintArray(arrB, n);//הדפסת המערך החדש

	printf("Second solution: ");
	if (second_solution(arrA, arrB, n)) {
		printf("Yes. \n");
	} else {
		printf("No. \n");
	}
	printf("A Array: ");
	PrintArray(arrA, n);//הדפסת המערך החדש
	printf("B Array: ");
	PrintArray(arrB, n);//הדפסת המערך החדש

	printf("First solution: ");
	if (first_solution(arrA, arrB, n)) {
		printf("Yes. \n");
	} else {
		printf("No. \n");
	}
	printf("A Array: ");
	PrintArray(arrA, n);//הדפסת המערך החדש
	printf("B Array: ");
	PrintArray(arrB, n);//הדפסת המערך החדש

	free(arrA);//שיחרור זיכרון
	free(arrB);
}

int first_solution(int first_array[], int second_array[], int array_length) {
	int i;
	MergeSort(first_array, 0, array_length - 1);
	MergeSort(second_array, 0, array_length - 1);
	for (i = 0; i < array_length; i++) {
		if (first_array[i] != second_array[i]) {
			return 0;
		}
	}
	return 1;
}

int* narrow_array(int array_to_change[], int place, int array_length) {
	for (place; (place + 1) < array_length; place++)
		array_to_change[place] = array_to_change[place + 1];
	return array_to_change;
}
int second_solution(int first_array[], int second_array[], int array_length) {
	int i;
	if (array_length > 0) {
		for (i = 0; i < array_length; i++) {
			if ((first_array[i]) == (second_array[array_length - 1])) {
				Swap(&first_array[i], &first_array[array_length - 1]);
				// first_array = narrow_array(first_array, i, array_length);
				// second_array = narrow_array(second_array, array_length - 1, array_length);
				return second_solution(first_array, second_array,
					array_length - 1);
			}
		}
		return 0;
	}
	return 1;
}

int third_solution(int first_array[], int second_array[], int array_length) {
	int new_array[100] = { 0 };
	int i;
	for (i = 0; i < array_length; i++)
		new_array[first_array[i] - 1]++;
	for (i = 0; i < array_length; i++)
		new_array[second_array[i] - 1]--;
	for (i = 0; i < 100; i++) {
		if (new_array[i] != 0) {
			// printf("New Array: ");
			// PrintArray(new_array, 17);//הדפסת המערך החדש
			// free(new_array); // אין צורך לשחרר;
			return 0;
		}
	}
	// free(new_array); // אין צורך לשחרר;
	return 1;
}


// ***** Ex5 *****
void Ex5()
{
	char *Str, c;
	Str = Create_new_string();

	printf("Please enter a letter: \n");
	scanf("%c",&c);

	printf("Please enter a string. That string is before the change: \n ");
	puts(Str);

	remove_letter(Str, c);

	printf("The string after change: \n");
	puts(Str);

	free(Str);
}
char *Create_new_string()// יצירת מחרוזת
{
	char *String_before_change, *String;
	printf("Please enter string: \n");
	String_before_change = (char*)malloc(256 * sizeof(char));
	flushall();
	gets(String_before_change);
	String = (char*)malloc((strlen(String_before_change) + 1)*sizeof(char));
	strcpy(String, String_before_change);
	free(String_before_change);
	return String;
}
void remove_letter(char *Str, char letter) //מחיקת כל המופעים של תו מהמחרוזת
{
	int i, k;
	i = 0;
	while (Str[i] != '\0')
	{
		if (Str[i] == letter)
		{
			k = i;
			while (Str[k] != '\0')
			{
				Str[k] = Str[k + 1];
				k++;
			}
		}
		else
			i++;
	}
}
