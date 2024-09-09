# include <stdio.h>
//Question#2
int main ()
{
	int int4;
	int int3;
	int int1;
	int int2;
	printf("Enter a Number: ");
	scanf("%d" , &int1);
	printf ("%d" ,int1);
	printf("\n")
	printf("Enter another number: ");
	printf("\n")
	scanf("%d" , &int2);
	printf ("%d" ,int2);
	int4 = int1;
	int3 = int2;
	int2 = int4;
	int1 = int3;
	printf ("%d" ,int1);
	printf("\n")
	printf("%d" ,int2);	
}
