/*
 * Name: Mustafa Bukhari
 * Roll#: 24k-0682
 * Desc: Question 4 Lab 4
 */
#include <stdio.h>

int main()
{
    float cost;
    float Discount;
    float Amount;

    printf("Enter the total cost of items: ");
    scanf("%f", &cost);

    if (cost < 200) {
        Discount = cost * 0.05;
    } else if (cost >= 200 && cost < 2000) {
        Discount = cost * 0.1;
    } else if (cost >= 2000 && cost < 4000) {
        Discount = cost * 0.15;
    } else if (cost >= 4000 && cost < 6000) {
        Discount = cost * 0.2;
    } else {
        Discount = cost * 0.35;
    }

    Amount = cost - Discount;
	
    printf("Total Cost is: %f\n", cost);
    printf("Amount saved is: %f\n", Discount);
    printf("Amount after the discount is: %f\n", Amount);

    return 0;
}
