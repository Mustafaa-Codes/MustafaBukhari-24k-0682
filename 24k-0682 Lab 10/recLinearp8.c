#include <stdio.h>
int linearSearch(int arr[], int size, int target, int index) {
    if (index >= size) {
        return -1;
    }

    if (arr[index] == target) {
        return index;
    }

    return linearSearch(arr, size, target, index + 1);
}

int main() {
    int size, target;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target element: ");
    scanf("%d", &target);
    int result = linearSearch(arr, size, target, 0);
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
