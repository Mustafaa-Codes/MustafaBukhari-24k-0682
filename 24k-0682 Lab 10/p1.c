#include <stdio.h>

void Recurrsivearr(int arr[], int size, int index) {
    if (index >= size) {
        return;
    }
    printf("%d ", arr[index]); 
    Recurrsivearr(arr, size, index + 1); 
}

int main() {
    int size;
    printf("Enter number of elements:\n");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements:\n");
    for (int j = 0; j < size; j++) {
        scanf("%d", &arr[j]);
    }
    printf("The elements of the array are:\n");
    Recurrsivearr(arr, size, 0);

    return 0;
}
