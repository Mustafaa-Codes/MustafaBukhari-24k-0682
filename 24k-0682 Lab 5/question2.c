/*
 * Name: Mustafa Bukhari
 * Roll#: 24k-0682
 * Desc: Question 2 Lab 5
*/
#include <stdio.h>
int main () {
	int sum;
	sum = 0;
	int number;
	printf("Enter a number:\n");
	scanf("%d",&number);
	while (number > 0) {
		sum += number % 10;
        number /= 10;
	}
	printf("Sum is %d",sum);
	return 0;
}