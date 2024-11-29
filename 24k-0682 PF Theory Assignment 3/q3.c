/*
Name:- Syed Mustafa Bukhari
Roll#:- 24k-0682
Question 3
Pf Assignment 3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char *email) {
    if (email == NULL || strlen(email) == 0) {
        return 0;
    }

    int atCount = 0;
    int dotAfterAt = 0;
    char *atPtr = NULL;

    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            atCount++;
            if (atCount == 1) {
                atPtr = &email[i];
            }
        }
        if (atCount == 1 && email[i] == '.' && atPtr != NULL && &email[i] > atPtr) {
            dotAfterAt = 1;
        }
    }
    return (atCount == 1 && dotAfterAt);
}

int main() {
    char *email;
    int bufferSize = 100;
    email = (char *)malloc(bufferSize * sizeof(char));
    if (email == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter an email address: ");
    fgets(email, bufferSize, stdin);

    size_t len = strlen(email);
    if (len > 0 && email[len - 1] == '\n') {
        email[len - 1] = '\0';
    }

    if (validateEmail(email)) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }

    free(email);

    return 0;
}
