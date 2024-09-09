#include <stdio.h>
//Question4
int main() {
    float FuelPriceForward;
    float FuelPriceBackward;
    float Distance;
    float Average;
    float Value;
    float PriceForward;
    float PriceBackward;

    FuelPriceForward = 118.0;
    FuelPriceBackward = 123.0;
    Distance = 1207.0;

    printf("Enter car's fuel average (in km per liter): ");
    scanf("%f", &Average);

    if (Average > 0) {
        Value = Distance / Average;
        printf("Your total fuel consumed is: %.2f liters\n", Value);

        PriceForward = Value * FuelPriceForward;
        printf("Your total fuel price for the trip going forward is: %.2f\n", PriceForward);

        PriceBackward = Value * FuelPriceBackward;
        printf("Your total fuel price for the trip going backward is: %.2f\n", PriceBackward);
    } else {
        printf("Car fuel average cannot be negative or zero.\n");
    }

    return 0;
}