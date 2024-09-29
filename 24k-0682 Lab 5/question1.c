/*
 * Name: Mustafa Bukhari
 * Roll#: 24k-0682
 * Desc: Question 1 Lab 5
*/
#include <stdio.h>
int main () {
	printf("Enter the year:\n");
	int Year;
	scanf("%d",&Year);
	if ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0)) {
		printf("It is a Leap Year\n");
    } else {
        printf("It is not a Leap Year\n");
    }
	
	return 0;
}
	