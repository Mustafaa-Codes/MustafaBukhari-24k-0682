/*
 * Name: Mustafa Bukhari
 * Roll#: 24k-0682
 * Desc: Question 5 Lab 4
*/
#include <stdio.h>

int main ()
{
float FinalAmount;
float SurCharge;	
float ChargePerUnit;
float Bill;
int CustomerID;
char CustomerName[100];
float ConsumedUnits;
printf("Enter CustomerID.\n", CustomerID);
scanf("%d",&CustomerID);
printf("Enter Customer Name.\n", CustomerName);
scanf("%s",&CustomerName);
printf("Enter Units Consumed.\n", ConsumedUnits);
scanf("%f",&ConsumedUnits);
if (ConsumedUnits<200) {
	Bill=ConsumedUnits*16.20;
	ChargePerUnit= 16.20;
}
else if  (ConsumedUnits>=200 && ConsumedUnits<300) {
	Bill=ConsumedUnits*20.10;
	ChargePerUnit=20.10;
}
else if  (ConsumedUnits>=300 && ConsumedUnits<500) {
	Bill=ConsumedUnits*27.10;
	ChargePerUnit=27.10;
}
else if  (ConsumedUnits>=500) {
	Bill=ConsumedUnits*35.90;
	ChargePerUnit=35.90;
}
if(Bill>18000);{
	SurCharge=Bill*0.15;
	FinalAmount= Bill + SurCharge;
}


printf("Customer ID: %d\n", CustomerID);
printf("Customer Name: %s\n", CustomerName);
printf("Units Consumed: %f\n", Bill);
printf("Amount Charges @Rs. %f per unit: %f\n",ChargePerUnit,Bill);
printf("Surcharge Amount: %f\n", SurCharge);
printf("Net Amount Paid by the Customer : %f", FinalAmount);

	








return 0;
}

