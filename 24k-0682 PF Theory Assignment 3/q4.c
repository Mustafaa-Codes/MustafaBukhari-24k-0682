/*
Name:- Syed Mustafa Bukhari
Roll#:- 24k-0682
Question 4
Pf Assignment 3
*/
#include <stdio.h>
#include <stdlib.h>

void inputEmployees(int **ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        printf("Enter ratings for Employee %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            int rating;
            do {
                printf("Period %d (1-10): ", j + 1);
                scanf("%d", &rating);
                if (rating < 1 || rating > 10) {
                    printf("Invalid rating! Please enter a value between 1 and 10.\n");
                }
            } while (rating < 1 || rating > 10);
            ratings[i][j] = rating;
        }
    }
}

void displayPerformance(int **ratings, int numEmployees, int numPeriods) {
    printf("\nPerformance Ratings:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d: ", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("%d ", ratings[i][j]);
        }
        printf("\n");
    }
}

int findEmployeeOfTheYear(int **ratings, int numEmployees, int numPeriods) {
    int topEmployee = 0;
    float highestAverage = 0;

    for (int i = 0; i < numEmployees; i++) {
        int total = 0;
        for (int j = 0; j < numPeriods; j++) {
            total += ratings[i][j];
        }
        float average = total / (float)numPeriods;
        if (average > highestAverage) {
            highestAverage = average;
            topEmployee = i;
        }
    }
    return topEmployee;
}

int findHighestRatedPeriod(int **ratings, int numEmployees, int numPeriods) {
    int topPeriod = 0;
    float highestAverage = 0;

    for (int j = 0; j < numPeriods; j++) {
        int total = 0;
        for (int i = 0; i < numEmployees; i++) {
            total += ratings[i][j];
        }
        float average = total / (float)numEmployees;
        if (average > highestAverage) {
            highestAverage = average;
            topPeriod = j;
        }
    }
    return topPeriod;
}

int findWorstPerformingEmployee(int **ratings, int numEmployees, int numPeriods) {
    int worstEmployee = 0;
    float lowestAverage = 10;

    for (int i = 0; i < numEmployees; i++) {
        int total = 0;
        for (int j = 0; j < numPeriods; j++) {
            total += ratings[i][j];
        }
        float average = total / (float)numPeriods;
        if (average < lowestAverage) {
            lowestAverage = average;
            worstEmployee = i;
        }
    }
    return worstEmployee;
}

int main() {
    int numEmployees, numPeriods;
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter the number of evaluation periods: ");
    scanf("%d", &numPeriods);
    int **ratings = (int **)malloc(numEmployees * sizeof(int *));
    for (int i = 0; i < numEmployees; i++) {
        ratings[i] = (int *)malloc(numPeriods * sizeof(int));
    }
    inputEmployees(ratings, numEmployees, numPeriods);
    displayPerformance(ratings, numEmployees, numPeriods);
    int topEmployee = findEmployeeOfTheYear(ratings, numEmployees, numPeriods);
    printf("\nEmployee of the Year: Employee %d\n", topEmployee + 1);
    int topPeriod = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
    printf("Highest Rated Period: Period %d\n", topPeriod + 1);
    int worstEmployee = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
    printf("Worst Performing Employee: Employee %d\n", worstEmployee + 1);

    for (int i = 0; i < numEmployees; i++) {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}
