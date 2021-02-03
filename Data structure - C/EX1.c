/* Created By Lizzy Asis */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Stack_arr.h"

typedef struct polynom
{
	int mekadem;
	unsigned int power;
	struct polynom *next;
	struct polynom *previous;
}polynom;

// Ex1 - Declaration start
void Ex1();
void Print (char operation , char item1 , char item2 , char counter);
void menu();
// Ex1 - Declaration end

// Ex2 - Declaration start
polynom *CreateEmpty(polynom *poli);
polynom *newFunctionElement(polynom **poli, int mekadem, unsigned int power);
polynom *SumPolynoms(polynom **poli1, polynom **poli2);
polynom *SubPolynoms(polynom **poli1, polynom **poli2);
polynom *MulPolynom(polynom **poli, int num);
int SederPolynom(polynom *poli);
void PrintPolynom(polynom **poli);
void FreePolyItems(polynom *poli);
void Ex2();
// Ex2 - Declaration end

void main()
{
	//Variables daclaration
	int select;
	menu();
	scanf ("%d", &select);
	while (select != 999)
	{
		switch (select)
		{
		case 1:
			Ex1();
			break;
		case 2:
			Ex2();
			break;
		default:
				printf("\n -------- Error Wrong Value -------- \n\n ");
				break;
		}
		printf("\n\n\n");
		printf("What do you want to do: ");
		scanf("%d", &select);
	}

	printf ("Goodbye! :)\n");
}

void menu()
{
	printf("\n ************************************************* \n");
	printf("\n *** Welcome To Lizzy Asis & Nicole Pochtar  *** \n");
	printf("\n ***    Lizzy Asis I.D: 311247555    *** \n");
	printf("\n ***    Nicole Pochtar I.D: 205985682    *** \n");
	printf("\n ************************************************** \n\n\n");
	printf("\n******************************************************\n");
	printf("Witch Exercise do you Choose 1 or 2? (Enter 999 to Exit) \n");
	printf("\n******************************************************\n");;
}


// Function Ex1 start
void Ex1() 
{
	char string[] = "A+B*C-D^2" , New , counter='Z';
	char item1, item2, operation;
	stack s1 , s2;
	int i;
	stack_type check, temp;
	create_stack (&s1);
	create_stack (&s2);
	printf ("| Operation |  Item  1  |  item  2  | Result  |\n");

	for (i = 0; string[i] != '\0'; i++)
	{
		New = string[i];
		if (New >= '0' && New <= '9' || New >= 'A' && New <='H')
		{
			push (New, &s1);
			continue;
		}
		if (stack_is_empty (&s2))
		{
			push (New, &s2);
			continue;
		}

		if (New == '^')
		{
			push (New, &s2);
			continue;
		}
		if ((New == '*') || (New == '/'))
		{
			stack_top (&s2, &check);
			if (check == '+' || check =='-')
			{
				push (New, &s2);
				continue;
			}
			else	
			{
				while (check == '^' || check== '/' || check == '*')
				{
					pop (&s2, &operation);
					pop (&s1, &item1);
					pop (&s1, &item2);
					Print (operation,item1,item2,counter);
					push(counter,&s1);
					counter--;
					stack_top (&s2, &check);
					if (stack_is_empty(&s2))
						break;
				}
				push(New, &s2);
			}

		}
		if ((New == '+') || (New == '-'))
		{
			stack_top (&s2, &check);

			while (!stack_is_empty (&s2))
			{
				pop (&s2, &operation);
				pop (&s1, &item1);
				pop (&s1, &item2);
				Print (operation, item1, item2, counter);
				push(counter, &s1);
				counter--;
				stack_top(&s2, &check);
			}
			push(New, &s2);

		}
	}
	while (!stack_is_empty (&s2))
	{
		pop (&s2, &operation);
		pop (&s1, &item1);
		pop (&s1, &item2);
		Print (operation, item1, item2, counter);
		push(counter, &s1);
		counter--;	
	}
}

void Print (char operation , char item1 , char item2 , char counter)
{
	printf ("|     %c     |     %c     |     %c     |     %c   |\n" ,operation ,item1 ,item2 , counter);

}

// Function Ex1 end


// Function Ex2 start

polynom *CreateEmpty(polynom *poli)
{
	poli = (polynom *)malloc(sizeof(polynom));
	poli->mekadem = 0;
	poli->power = 0;
	poli->next = NULL;
	poli->previous = NULL;
	return poli;
}

polynom *newFunctionElement(polynom **poli, int mekadem, unsigned int power) // Adding new elements into the polynom 
{
	polynom *newPol;
	polynom *temp;
	newPol = (polynom *)malloc(sizeof(polynom));
	newPol->mekadem = mekadem;
	newPol->power = power;
	newPol->next = NULL;
	newPol->previous = NULL;
	temp = *poli;
	if (*poli == NULL)
	{
		*poli = newPol;
	}
	else if ((*poli)->power == power)
	{
		(*poli)->mekadem = mekadem;
	}
	else if ((*poli)->power > power)
	{
		newPol->next = temp;
		temp->previous = newPol;
		*poli = newPol;
	}
	else {
		while (temp->next != NULL && temp->power < power)
		{
			temp = temp->next;
		}
		if (temp->power == power)
		{
			temp->mekadem = mekadem;
			return *poli;
		}
		if (temp->next == NULL)
		{
			temp->next = newPol;
			newPol->previous = temp;
		}
		else 
		{
			temp->previous->next = newPol;
			newPol->next = temp;
		}
		return *poli;
	}
}


polynom *SumPolynoms(polynom **poli1, polynom **poli2) // Calculating the sum of 2 polynoms
{
	int relevantPower = NULL;

	polynom *p1, *p2, *newPolynom = NULL;
	p1 = *poli1;
	p2 = *poli2;
	while (p1 != NULL && p2 != NULL)
	{
		relevantPower = p1->power;
		if (relevantPower > p2->power) 
		{
			newFunctionElement(&newPolynom, p2->mekadem, p2->power);
			p2 = p2->next;
		}
		else if (relevantPower < p2->power) 
		{
			newFunctionElement(&newPolynom, p1->mekadem, relevantPower);
			p1 = p1->next;
		}
		else 
		{
			newFunctionElement(&newPolynom, (p1->mekadem) + (p2->mekadem), relevantPower);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	while (p1 != NULL)
	{
		newFunctionElement(&newPolynom, p1->mekadem, p1->power);
		p1 = p1->next;
	}
	while (p2 != NULL)
	{
		newFunctionElement(&newPolynom, p2->mekadem, p2->power);
		p2 = p2->next;
	}
	return newPolynom;
}


polynom *SubPolynoms(polynom **poli1, polynom **poli2) // Calculating the subtraction of 2 polynoms
{
	int relevantPower = NULL;

	polynom *p1, *p2, *newPolynom = NULL;
	p1 = *poli1;
	p2 = *poli2;
	while (p1 != NULL && p2 != NULL)
	{
		relevantPower = p1->power;
		if (relevantPower > p2->power) {
			newFunctionElement(&newPolynom, p2->mekadem, p2->power);
			p2 = p2->next;
		}
		else if (relevantPower < p2->power) {
			newFunctionElement(&newPolynom, p1->mekadem, relevantPower);
			p1 = p1->next;
		}
		else {
			newFunctionElement(&newPolynom, (p1->mekadem) - (p2->mekadem), relevantPower);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	while (p1 != NULL) {
		newFunctionElement(&newPolynom, p1->mekadem, p1->power);
		p1 = p1->next;
	}
	while (p2 != NULL) {
		newFunctionElement(&newPolynom, p2->mekadem, p2->power);
		p2 = p2->next;
	}
	return newPolynom;
}

polynom *MulPolynom(polynom **poli, int num) // Calculating the multiplication of 2 polynoms
{
	polynom *p1 = *poli;
	polynom *newPolynom = NULL;
	if (num == 0)
	{
		return newPolynom;
	}
	else
	{
		while (p1 != NULL)
		{
			newFunctionElement(&newPolynom, (p1->mekadem)*num, p1->power);
			p1 = p1->next;
		}
	}
	return newPolynom;
}

int SederPolynom(polynom *poli) // Finding the highest power of polynoms
{
	polynom *p1 = poli;
	if (p1 == NULL)
		return -1;
	else {
		while (p1->next != NULL) {
			p1 = p1->next;
		}
		return p1->power;
	}
}

void PrintPolynom(polynom **poli) // Printing the polynom from the highest power to the lowest power
{
	int mekadem = NULL;

	polynom *temp = *poli;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	if (temp->mekadem == -1)
		printf("-x^%d", temp->power);
	printf("%dx^%d", temp->mekadem, temp->power);

	while (temp->previous != NULL)
	{
		temp = temp->previous;
		mekadem = temp->mekadem;
		if (mekadem < 0) 
		{
			if (mekadem == -1)
				printf("-x^%d", temp->power);
			else
				printf("-%dx^%d", temp->mekadem, temp->power);
		}
		else 
		{
			if (mekadem == 1)
				printf("+x^%d", temp->power);
			else
				printf("+%dx^%d", temp->mekadem, temp->power);
		}
	}
	printf("\n");
}

void FreePolyItems(polynom *poli) // Resetting the polynom
{
	polynom *temp;
	polynom *poly = poli;
	while (poly != NULL)
	{
		temp = poly;
		poly = poly->next;
		free(temp);
	}
	poly->next = NULL;
	poly->previous = NULL;
}


void Ex2()
{
	polynom *poli = NULL, *poli2 = NULL, *poli3 = NULL;
	int choice, mekadem, power, mul;
	printf("Enter your choice:\n1: Create empty polynom\n2:Insert Elements\n3:Sum two polynoms\n");
	printf("4:Sub two polynoms\n5: Mul Polynom\n6:Power of polynom\n7:Clear all\n-1: Close\n");
	scanf_s("%d", &choice);
	while (choice != -1)
	{
		switch (choice)
		{
		case 1:
			CreateEmpty(poli);
			break;
		case 2:
			printf("Please enter a mekadem, power. End by entering 0 0\n");
			scanf_s("%d %d", &mekadem, &power);
			while (mekadem != 0 || power != 0) {
				newFunctionElement(&poli, mekadem, power);
				printf("add another one?\n");
				scanf_s("%d %d", &mekadem, &power);
				
			}
			PrintPolynom(&poli);
			break;
		case 3:
			printf("Please enter a mekadem, power for second polynom. End by entering 0 0\n");
			scanf_s("%d %d", &mekadem, &power);
			while (mekadem != 0 || power != 0) {
				newFunctionElement(&poli2, mekadem, power);
				printf("add another one?\n");
				scanf_s("%d %d", &mekadem, &power);
			}
			PrintPolynom(&poli2);
			poli3 = SumPolynoms(&poli, &poli2);
			printf("The Sum is:");
			PrintPolynom(&poli3);
			break;
		case 4:
			printf("Please enter a mekadem, power for second polynom. End by entering 0 0\n");
			scanf_s("%d %d", &mekadem, &power);
			while (mekadem != 0 || power != 0) {
				newFunctionElement(&poli2, mekadem, power);
				printf("add another one?\n");
				scanf_s("%d %d", &mekadem, &power);
			}
			PrintPolynom(&poli2);
			poli3 = SubPolynoms(&poli, &poli2);
			printf("The Sub is:");
			PrintPolynom(&poli3);
			break;
		case 5:
			printf("Enter number to multiply polynom:");
			scanf_s("%d", &mul);
			poli3 = MulPolynom(&poli, mul);
			PrintPolynom(&poli3);
			break;
		case 6:
			printf("The Seder of the polynom is :%d\n", SederPolynom(poli));
			break;
		case 7:
			FreePolyItems(poli);
			FreePolyItems(poli2);
			FreePolyItems(poli3);
			printf("All clear\n");
			break;
		default:
			printf("Command Not Found - Try Again\n");
			break;
		}
		printf("What to do next?");
		scanf_s("%d", &choice);
	}
	getchar();
}

// Function Ex2 end
