#include<stdio.h>

int main(){

    int arr[3][3];
    int i, j, k, l, smallestInrow, largestIncol;

    for ( i = 0; i < 3; i++){
        for ( j = 0; j < 3; j++){
            printf("Enter %d row and %d column number :", i+1, j+1);
            scanf("%d",&arr[i][j]);
        }
    }

    printf("The given Matix is :\n");

    for ( i = 0; i < 3; i++){
        for ( j = 0; j < 3; j++){
            printf("%2d", arr[i][j]);
        }
        printf("\n");
    } 

    for( i = 0; i < 3; i++){
        for ( j = 0; j < 3; j++){ 
            largestIncol = arr[i][j];
            smallestInrow = arr[i][j];
            for ( k = 0; k < 3; k++){
                if(arr[i][k]<smallestInrow){
                    smallestInrow =  arr[i][k];
                }
                if(arr[k][j]>largestIncol){
                    largestIncol = arr[k][j];
                }
            }
            if(smallestInrow==arr[i][j] && largestIncol==arr[i][j])
                printf("The %d is the saddle pointe located at at %d row and %d column \n", arr[i][j], i+1, j+1);
        }
    }
    return 0;
}