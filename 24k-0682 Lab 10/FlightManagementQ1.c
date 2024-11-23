#include <stdio.h>

struct FlightInformation {
    int flightnum;
    char departurecity[20];
    char destinationcity[20];
    char date[20];
    int availableseats;
};

int main() {
    struct FlightInformation FlightDetails[3] = {
        {1, "LA", "Chicago", "12/1/24", 5},
        {2, "NewYork", "Boston", "12/6/24", 5},
        {3, "Miami", "Dallas", "11/27/24", 5}
    };

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display Flight Details\n");
        printf("2. Book a Seat\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                for (int i = 0; i < 3; i++) {
                    printf("\nFlight Number: %d\n", FlightDetails[i].flightnum);
                    printf("Departure City: %s\n", FlightDetails[i].departurecity);
                    printf("Destination City: %s\n", FlightDetails[i].destinationcity);
                    printf("Date: %s\n", FlightDetails[i].date);
                    printf("Available Seats: %d\n", FlightDetails[i].availableseats);
                }
                break;
            }

            case 2: {
                int num, found = 0;
                printf("Enter Flight Number: ");
                scanf("%d", &num);

                for (int i = 0; i < 3; i++) {
                    if (FlightDetails[i].flightnum == num) {
                        found = 1;
                        if (FlightDetails[i].availableseats > 0) {
                            FlightDetails[i].availableseats--;
                            printf("Seat Booked Successfully! Remaining seats: %d\n", FlightDetails[i].availableseats);
                        } else {
                            printf("Flight is full.\n");
                        }
                        break;
                    }
                }

                if (!found) {
                    printf("Incorrect Flight Number.\n");
                }
                break;
            }

            case 3:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
