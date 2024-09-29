/*
 * Name: Mustafa Bukhari
 * Roll#: 24k-0682
 * Desc: Question 6 Lab 5
*/
#include <stdio.h>
int main() {
    int age;
    float income;
    int creditscore;
    int Eligibility;
    printf("Enter your age:\n ");
    scanf("%d", &age);
	printf("Enter your annual income:\n ");
    scanf("%f", &income);
	printf("Enter your credit score:\n ");
    scanf("%d", &creditscore);
    Eligibility = (age >= 18) && (income >= 30000) && (creditscore >= 650);
    if (Eligibility) {
        printf("You are eligible for the loan\n");
    } else {
        printf("You are not eligible for the loan\n");
    }

    return 0;
}