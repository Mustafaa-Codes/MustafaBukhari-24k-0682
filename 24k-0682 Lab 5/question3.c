/*
 * Name: Mustafa Bukhari
 * Roll#: 24k-0682
 * Desc: Question 3 Lab 5
*/
#include <stdio.h>
int main () {
	int greatest;
	int num1;
	int num2;
	int num3;	
	greatest=0;
	printf("Enter three numbers\n");
	scanf("%d",&num1);
	scanf("%d",&num2);
	scanf("%d",&num3);	
	if (num1>num2) {
		if (num1>num3) {
			greatest = num1;
		}
	}
	if (num2>num1) {
			if (num2>num3) {
				greatest = num2;
			}
	}
	if (num3>num1) {
		if (num3>num2) {
			greatest = num3;
		}
	}

		
	printf("The greatest number is: %d",greatest);
	return 0;
}


