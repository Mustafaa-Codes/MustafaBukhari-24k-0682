#include <stdio.h>
//Question#3
int main ()
{
	float Salary2;
	float FinalSalary;
	float TaxRate;
	float Salary;
	printf("Enter Tax Rate");
	scanf("%f" , &TaxRate);
	printf("Enter Salary");
	scanf("%f" , &Salary);
	Salary2 = (Salary *((TaxRate)/100));
	printf("Your tax to be paid is: ");
	printf ("%f" ,Salary2);
	FinalSalary = (Salary - Salary2);
	printf("Your Final Salary after the tax is");
	printf ("%f" ,FinalSalary);
	return 0;
	
}
