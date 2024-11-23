#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 100

struct TravelPackage {
    char name[50];
    char destination[50];
    int duration;      
    float cost;        
    int seatsAvailable; 
};

void displayPackages(struct TravelPackage packages[], int count);
void bookPackage(struct TravelPackage packages[], int count);

int main() {
    struct TravelPackage packages[MAX_PACKAGES];
    int packageCount = 0;


    strcpy(packages[0].name, "Beach Paradise");
    strcpy(packages[0].destination, "Maldives");
    packages[0].duration = 5;
    packages[0].cost = 1500.00;
    packages[0].seatsAvailable = 10;

    strcpy(packages[1].name, "Mountain Adventure");
    strcpy(packages[1].destination, "Swiss Alps");
    packages[1].duration = 7;
    packages[1].cost = 2500.00;
    packages[1].seatsAvailable = 8;

    strcpy(packages[2].name, "City Break");
    strcpy(packages[2].destination, "New York");
    packages[2].duration = 3;
    packages[2].cost = 1200.00;
    packages[2].seatsAvailable = 15;

    packageCount = 3;

    int choice;

    do {
        printf("\nTravel Package System\n");
        printf("1. Display Available Packages\n");
        printf("2. Book a Package\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPackages(packages, packageCount);
                break;
            case 2:
                bookPackage(packages, packageCount);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void displayPackages(struct TravelPackage packages[], int count) {
    if (count == 0) {
        printf("No packages available.\n");
        return;
    }

    printf("\nAvailable Travel Packages:\n");
    printf("Index | Name             | Destination    | Duration | Cost   | Seats\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d | %-15s | %-15s | %-8d | $%-6.2f | %-5d\n", 
               i + 1, packages[i].name, packages[i].destination, 
               packages[i].duration, packages[i].cost, packages[i].seatsAvailable);
    }
}

void bookPackage(struct TravelPackage packages[], int count) {
    if (count == 0) {
        printf("No packages available for booking.\n");
        return;
    }

    int packageIndex, seatsToBook;

    displayPackages(packages, count);

    printf("\nEnter the index of the package you want to book: ");
    scanf("%d", &packageIndex);

    if (packageIndex < 1 || packageIndex > count) {
        printf("Invalid package index. Please try again.\n");
        return;
    }

    packageIndex--;

    printf("Enter the number of seats to book: ");
    scanf("%d", &seatsToBook);
    if (seatsToBook <= 0 || seatsToBook > packages[packageIndex].seatsAvailable) {
        printf("Invalid number of seats or not enough seats available.\n");
        return;
    }

    packages[packageIndex].seatsAvailable -= seatsToBook;
    printf("Successfully booked %d seats for the package '%s' to %s.\n",
           seatsToBook, packages[packageIndex].name, packages[packageIndex].destination);
}
