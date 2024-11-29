/*
Name:- Syed Mustafa Bukhari
Roll#:- 24k-0682
Question 7
Pf Assignment 3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    float rating;
    int runtime;
    char encodingFormats[50];
} ContentMetadata;

double** initializeEngagementMatrix(int numUsers, int numCategories);
void updateEngagement(double** engagementMatrix, int userIndex, int categoryIndex, double score);
void freeEngagementMatrix(double** engagementMatrix, int numUsers);

char*** initializeDeviceMatrix(int numUsers, int numDevices);
void updateDevicePreferences(char*** deviceMatrix, int userIndex, int deviceIndex, const char* preference);
void freeDeviceMatrix(char*** deviceMatrix, int numUsers, int numDevices);

ContentMetadata** initializeContentMetadata(int numCategories, int numContents);
void freeContentMetadata(ContentMetadata** contentMatrix, int numCategories);

void displaySystemData(double** engagementMatrix, char*** deviceMatrix, ContentMetadata** contentMatrix, 
                       int numUsers, int numCategories, int numDevices, int numContents);

int main() {
    int numUsers = 3;
    int numCategories = 3;
    int numDevices = 2;
    int numContents = 2;


    double** engagementMatrix = initializeEngagementMatrix(numUsers, numCategories);

    updateEngagement(engagementMatrix, 0, 0, 5.0);
    updateEngagement(engagementMatrix, 1, 1, 8.5);
    updateEngagement(engagementMatrix, 2, 2, 7.2);

   
    char*** deviceMatrix = initializeDeviceMatrix(numUsers, numDevices);


    updateDevicePreferences(deviceMatrix, 0, 0, "1080p");
    updateDevicePreferences(deviceMatrix, 1, 1, "4K");
    updateDevicePreferences(deviceMatrix, 2, 0, "720p");

    ContentMetadata** contentMatrix = initializeContentMetadata(numCategories, numContents);

    displaySystemData(engagementMatrix, deviceMatrix, contentMatrix, 
                      numUsers, numCategories, numDevices, numContents);

    freeEngagementMatrix(engagementMatrix, numUsers);
    freeDeviceMatrix(deviceMatrix, numUsers, numDevices);
    freeContentMetadata(contentMatrix, numCategories);

    return 0;
}

double** initializeEngagementMatrix(int numUsers, int numCategories) {
    double** matrix = (double**)malloc(numUsers * sizeof(double*));
    for (int i = 0; i < numUsers; i++) {
        matrix[i] = (double*)malloc(numCategories * sizeof(double));
        for (int j = 0; j < numCategories; j++) {
            matrix[i][j] = 0.0; 
        }
    }
    return matrix;
}

void updateEngagement(double** engagementMatrix, int userIndex, int categoryIndex, double score) {
    engagementMatrix[userIndex][categoryIndex] = score;
}

void freeEngagementMatrix(double** engagementMatrix, int numUsers) {
    for (int i = 0; i < numUsers; i++) {
        free(engagementMatrix[i]);
    }
    free(engagementMatrix);
}

char*** initializeDeviceMatrix(int numUsers, int numDevices) {
    char*** matrix = (char***)malloc(numUsers * sizeof(char**));
    for (int i = 0; i < numUsers; i++) {
        matrix[i] = (char**)malloc(numDevices * sizeof(char*));
        for (int j = 0; j < numDevices; j++) {
            matrix[i][j] = NULL; 
        }
    }
    return matrix;
}

void updateDevicePreferences(char*** deviceMatrix, int userIndex, int deviceIndex, const char* preference) {
    deviceMatrix[userIndex][deviceIndex] = (char*)malloc((strlen(preference) + 1) * sizeof(char));
    strcpy(deviceMatrix[userIndex][deviceIndex], preference);
}


void freeDeviceMatrix(char*** deviceMatrix, int numUsers, int numDevices) {
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numDevices; j++) {
            free(deviceMatrix[i][j]);
        }
        free(deviceMatrix[i]);
    }
    free(deviceMatrix);
}
ContentMetadata** initializeContentMetadata(int numCategories, int numContents) {
    ContentMetadata** matrix = (ContentMetadata**)malloc(numCategories * sizeof(ContentMetadata*));
    for (int i = 0; i < numCategories; i++) {
        matrix[i] = (ContentMetadata*)malloc(numContents * sizeof(ContentMetadata));
        for (int j = 0; j < numContents; j++) {
            sprintf(matrix[i][j].title, "Content_%d_%d", i + 1, j + 1);
            matrix[i][j].rating = 8.0 + (i * 0.5 + j * 0.2); 
            matrix[i][j].runtime = 90 + (i * 10 + j * 5); 
            strcpy(matrix[i][j].encodingFormats, "H.264, H.265");
        }
    }
    return matrix;
}


void freeContentMetadata(ContentMetadata** contentMatrix, int numCategories) {
    for (int i = 0; i < numCategories; i++) {
        free(contentMatrix[i]);
    }
    free(contentMatrix);
}

void displaySystemData(double** engagementMatrix, char*** deviceMatrix, ContentMetadata** contentMatrix, 
                       int numUsers, int numCategories, int numDevices, int numContents) {
    printf("\n--- Engagement Matrix ---\n");
    for (int i = 0; i < numUsers; i++) {
        printf("User %d: ", i + 1);
        for (int j = 0; j < numCategories; j++) {
            printf("%.2f ", engagementMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\n--- Device Preferences ---\n");
    for (int i = 0; i < numUsers; i++) {
        printf("User %d:\n", i + 1);
        for (int j = 0; j < numDevices; j++) {
            if (deviceMatrix[i][j]) {
                printf("  Device %d: %s\n", j + 1, deviceMatrix[i][j]);
            } else {
                printf("  Device %d: No Preference\n", j + 1);
            }
        }
    }

    printf("\n--- Content Metadata ---\n");
    for (int i = 0; i < numCategories; i++) {
        printf("Category %d:\n", i + 1);
        for (int j = 0; j < numContents; j++) {
            printf("  Title: %s, Rating: %.2f, Runtime: %d mins, Formats: %s\n",
                   contentMatrix[i][j].title, contentMatrix[i][j].rating, 
                   contentMatrix[i][j].runtime, contentMatrix[i][j].encodingFormats);
        }
    }
}
