/*
 * Name: Mustafa Bukhari
 * Roll#: 24k-0682
 * Desc: Question 3 Lab 4
*/
#include <stdio.h>

int main ()
{
char Character;	
printf("enter a character");
scanf("%c", &Character);
if (Character >= 'a' && Character <= 'z') {
	printf("Small Alphabet'%c'.\n",Character);
}
else if (Character >= 'A' && Character <= 'Z') {
	printf("Capital letter '%c'.\n",Character);
}
else if (Character >= '0' && Character <= '9') {
	printf("Digit '%c'.\n",Character);
}
else {
	printf("Special Character '%c'.\n",Character);
}
	return 0;
}

