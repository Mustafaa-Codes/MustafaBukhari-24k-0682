/*
 * Name: Mustafa Bukhari
 * Roll#: 24k-0682
*/
#include <stdio.h>

int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];  
    int max = 0; 
    for(int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
        if(arr[i] > max) max = arr[i];
    }

    printf("\nHorizontal Histogram:\n");
    for(int i = 0; i < n; i++) {
        printf("Value %d: ", i + 1);
        for(int j = 0; j < arr[i]; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\nVertical Histogram:\n");
    for(int i = 0; i < max; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[j] >= max - i) printf("* ");
            else printf("  ");
        }
        printf("\n");
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

    
