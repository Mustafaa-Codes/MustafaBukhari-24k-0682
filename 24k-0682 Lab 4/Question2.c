/*
 * Name: Mustafa Bukhari
 * Roll#: 24k-0682
 * Desc: Question 2 Lab 4
*/
#include <stdio.h>

int main ()
{
	int Num1,Num2;
	char Op;
	int Answer;
	printf("Enter two numbers Numbers and an Operator");
	printf("\n");
	scanf("%d",&Num1);
	scanf("%d",&Num2);
	scanf(" %c",&Op);
	switch (Op) {
		case '+':
			Answer=Num1+Num2;
			printf("%d", Answer);
			break;
		case '-':
			Answer=Num1-Num2;
			printf("%d", Answer);
			break;
		case '*':
			Answer=Num1*Num2;
			printf("%d", Answer);
			break;
		case '/':
			Answer=Num1/Num2;
			printf("%d", Answer);
			break;
		default:
			printf("Invalid Operator");
	}
	
	
	return Answer;
}
