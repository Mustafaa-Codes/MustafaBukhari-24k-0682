/*
 * Name: Mustafa Bukhari
 * Roll#: 24k-0682
 * Desc: Question 1 Lab 4
*/
#include <stdio.h>

int main ()
{
	int Number;
	int Multiple;
	printf("Enter a Number");
	scanf("%d",&Number);
	Multiple = Number % 3;
	if (Multiple==0){
		printf("Multiple of 3");
	}
	else{
		printf("not a multiple of 3");	
	}
	
	return 0;
}



