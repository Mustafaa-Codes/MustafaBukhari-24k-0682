#include<stdio.h>

int main(){

    int  arr[3][3] , arr2[3][3] , ansarr[3][3]={0};

    for(int i = 0; i <  3; i++){
        for(int j = 0; j < 3; j++ ){
            printf("Enter the %d  %d element of the first array: ", i+1 , j+1);
            scanf("%d" , &arr[i][j]);
        }
    }

    for(int i = 0; i <  3; i++){
        for(int j = 0; j < 3; j++ ){
            printf("Enter the %d  %d element of the Second array: ", i+1 , j+1);
            scanf("%d" , &arr2[i][j]);
        } 
    }

    for(int i = 0; i < 3; i++){
        for(int l = 0; l < 3; l++){
            for(int j = 0 ; j < 3; j++){
                ansarr[i][l] +=  arr[i][j]*arr2[j][i];
            }
        }
    }

    for(int i = 0; i <  3; i++){
        for(int j = 0; j < 3; j++ ){
            printf(" %d ", ansarr[i][j]);
        }
        printf("\n");
    }

    return 0;
}