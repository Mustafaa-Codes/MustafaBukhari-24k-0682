#include <stdio.h>
//Question 5
int main() 
{
	float Princple;
	float Rate;
	float Time;
	float SimpleInterest;
	printf("enter principle value between Rs.100 to Rs.1,000,000:" );
	scanf("%f",&Princple);
	printf("enter rate value between 5 to 10 percent: ");
	scanf("%f",&Rate);
	printf("enter time period between 1 to 10 years:" );
	scanf("%f",&Time);
	SimpleInterest=(Princple*Rate*Time) / 100;
	printf("your simple interest is %f",SimpleInterest);
}