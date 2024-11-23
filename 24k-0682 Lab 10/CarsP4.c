#include <stdio.h>
#include <string.h>

#define MAX_CARS 100

struct Car {
    char make[50];
    char model[50];
    int year;
    float price;
    float mileage;
};

void addCar(struct Car cars[], int *carCount);
void displayCars(struct Car cars[], int carCount);
void searchCars(struct Car cars[], int carCount);

int main() {
    struct Car cars[MAX_CARS];
    int carCount = 0; 
    int choice;

    do {
        printf("\nCar Dealership System\n");
        printf("1. Add New Car\n");
        printf("2. Display All Cars\n");
        printf("3. Search Cars by Make or Model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (carCount < MAX_CARS) {
                    addCar(cars, &carCount);
                } else {
                    printf("Car inventory is full.\n");
                }
                break;
            case 2:
                displayCars(cars, carCount);
                break;
            case 3:
                searchCars(cars, carCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
void addCar(struct Car cars[], int *carCount) {
    printf("Enter car make: ");
    scanf("%s", cars[*carCount].make);
    printf("Enter car model: ");
    scanf("%s", cars[*carCount].model);
    printf("Enter car year: ");
    scanf("%d", &cars[*carCount].year);
    printf("Enter car price: ");
    scanf("%f", &cars[*carCount].price);
    printf("Enter car mileage: ");
    scanf("%f", &cars[*carCount].mileage);

    (*carCount)++;
    printf("Car added successfully!\n");
}

void displayCars(struct Car cars[], int carCount) {
    if (carCount == 0) {
        printf("No cars available.\n");
        return;
    }

    printf("\nAvailable Cars:\n");
    printf("Make\tModel\tYear\tPrice\tMileage\n");
    for (int i = 0; i < carCount; i++) {
        printf("%s\t%s\t%d\t%.2f\t%.2f\n",
               cars[i].make, cars[i].model, cars[i].year, cars[i].price, cars[i].mileage);
    }
}

// Function to search for cars by make or model
void searchCars(struct Car cars[], int carCount) {
    if (carCount == 0) {
        printf("No cars available to search.\n");
        return;
    }

    char query[50];
    int found = 0;

    printf("Enter the make or model to search: ");
    scanf("%s", query);

    printf("\nSearch Results:\n");
    printf("Make\tModel\tYear\tPrice\tMileage\n");
    for (int i = 0; i < carCount; i++) {
        if (strcmp(cars[i].make, query) == 0 || strcmp(cars[i].model, query) == 0) {
            printf("%s\t%s\t%d\t%.2f\t%.2f\n",
                   cars[i].make, cars[i].model, cars[i].year, cars[i].price, cars[i].mileage);
            found = 1;
        }
    }

    if (!found) {
        printf("No cars found matching '%s'.\n", query);
    }
}
