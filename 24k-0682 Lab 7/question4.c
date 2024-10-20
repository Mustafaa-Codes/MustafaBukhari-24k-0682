#include <stdio.h>
int main() {
    int Array[] = {2, 3, 1, 2, 3};  
    int n = sizeof(Array) / sizeof(Array[0]);  
    int i;
    
    
    for (i = 0; i < n; i++) {
        int index = Array[i] % n;
        Array[index] += n;
    }
    printf("The repeating elements are: ");
    int found = 0;
    for (i = 0; i < n; i++) {
        if (Array[i] / n > 1) {
            printf("%d ", i);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No duplicates found.");
    }
    
    printf("\n");
}