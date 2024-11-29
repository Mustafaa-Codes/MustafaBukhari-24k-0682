/*
Name:- Syed Mustafa Bukhari
Roll#:- 24k-0682
Question 5
Pf Assignment 3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeInventory(char ***speciesSupplies, int *numSupplies, int numSpecies);
void addSupplies(char ***speciesSupplies, int *numSupplies, int speciesIndex);
void updateSupplies(char ***speciesSupplies, int *numSupplies, int speciesIndex);
void removeSpecies(char ***speciesSupplies, int *numSupplies, int *numSpecies, int speciesIndex);
void displayInventory(char ***speciesSupplies, int *numSupplies, int numSpecies);
void freeInventory(char ***speciesSupplies, int *numSupplies, int numSpecies);

int main() {
    int numSpecies;
    printf("Enter the number of species: ");
    scanf("%d", &numSpecies);
    getchar();

    char **speciesSupplies[numSpecies];
    int numSupplies[numSpecies]; 

    initializeInventory(speciesSupplies, numSupplies, numSpecies);

    int choice;
    do {
        printf("\n--- Pets in Heart Inventory System ---\n");
        printf("1. Add Supplies for a Species\n");
        printf("2. Update a Supply for a Species\n");
        printf("3. Remove a Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                int speciesIndex;
                printf("Enter the species index (0 to %d): ", numSpecies - 1);
                scanf("%d", &speciesIndex);
                getchar();
                if (speciesIndex >= 0 && speciesIndex < numSpecies) {
                    addSupplies(speciesSupplies, numSupplies, speciesIndex);
                } else {
                    printf("Invalid species index!\n");
                }
                break;
            }
            case 2: {
                int speciesIndex;
                printf("Enter the species index (0 to %d): ", numSpecies - 1);
                scanf("%d", &speciesIndex);
                getchar();
                if (speciesIndex >= 0 && speciesIndex < numSpecies) {
                    updateSupplies(speciesSupplies, numSupplies, speciesIndex);
                } else {
                    printf("Invalid species index!\n");
                }
                break;
            }
            case 3: {
                int speciesIndex;
                printf("Enter the species index (0 to %d) to remove: ", numSpecies - 1);
                scanf("%d", &speciesIndex);
                getchar();
                if (speciesIndex >= 0 && speciesIndex < numSpecies) {
                    removeSpecies(speciesSupplies, numSupplies, &numSpecies, speciesIndex);
                } else {
                    printf("Invalid species index!\n");
                }
                break;
            }
            case 4:
                displayInventory(speciesSupplies, numSupplies, numSpecies);
                break;
            case 5:
                freeInventory(speciesSupplies, numSupplies, numSpecies);
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void initializeInventory(char ***speciesSupplies, int *numSupplies, int numSpecies) {
    for (int i = 0; i < numSpecies; i++) {
        speciesSupplies[i] = NULL;
        numSupplies[i] = 0; 
    }
}

void addSupplies(char ***speciesSupplies, int *numSupplies, int speciesIndex) {
    int numNewSupplies;
    printf("Enter the number of supplies to add for species %d: ", speciesIndex);
    scanf("%d", &numNewSupplies);
    getchar();

    speciesSupplies[speciesIndex] = realloc(speciesSupplies[speciesIndex], 
                                            (numSupplies[speciesIndex] + numNewSupplies) * sizeof(char *));
    for (int i = 0; i < numNewSupplies; i++) {
        printf("Enter the name of supply %d: ", numSupplies[speciesIndex] + i + 1);
        char buffer[100];
        fgets(buffer, 100, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; 

        speciesSupplies[speciesIndex][numSupplies[speciesIndex] + i] = strdup(buffer);
    }

    numSupplies[speciesIndex] += numNewSupplies;
}

void updateSupplies(char ***speciesSupplies, int *numSupplies, int speciesIndex) {
    if (numSupplies[speciesIndex] == 0) {
        printf("No supplies found for species %d!\n", speciesIndex);
        return;
    }

    int supplyIndex;
    printf("Enter the supply index to update (0 to %d): ", numSupplies[speciesIndex] - 1);
    scanf("%d", &supplyIndex);
    getchar();

    if (supplyIndex >= 0 && supplyIndex < numSupplies[speciesIndex]) {
        printf("Enter the new name for supply %d: ", supplyIndex);
        char buffer[100];
        fgets(buffer, 100, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; 

        free(speciesSupplies[speciesIndex][supplyIndex]);
        speciesSupplies[speciesIndex][supplyIndex] = strdup(buffer);
    } else {
        printf("Invalid supply index!\n");
    }
}

void removeSpecies(char ***speciesSupplies, int *numSupplies, int *numSpecies, int speciesIndex) {
    for (int i = 0; i < numSupplies[speciesIndex]; i++) {
        free(speciesSupplies[speciesIndex][i]);
    }
    free(speciesSupplies[speciesIndex]);

    for (int i = speciesIndex; i < *numSpecies - 1; i++) {
        speciesSupplies[i] = speciesSupplies[i + 1];
        numSupplies[i] = numSupplies[i + 1];
    }

    (*numSpecies)--;
    printf("Species %d removed successfully.\n", speciesIndex);
}

void displayInventory(char ***speciesSupplies, int *numSupplies, int numSpecies) {
    printf("\n--- Inventory ---\n");
    for (int i = 0; i < numSpecies; i++) {
        printf("Species %d: ", i);
        if (numSupplies[i] == 0) {
            printf("No supplies.\n");
        } else {
            for (int j = 0; j < numSupplies[i]; j++) {
                printf("%s ", speciesSupplies[i][j]);
            }
            printf("\n");
        }
    }
}

void freeInventory(char ***speciesSupplies, int *numSupplies, int numSpecies) {
    for (int i = 0; i < numSpecies; i++) {
        for (int j = 0; j < numSupplies[i]; j++) {
            free(speciesSupplies[i][j]);
        }
        free(speciesSupplies[i]);
    }
}
