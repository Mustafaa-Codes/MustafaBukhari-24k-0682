#include<stdio.h>
int main(){

    int arr[2][3][3];
    int i , j , k;

    for(i = 0; i < 2; i++){
        for(j = 0; j < 3; j++){
            for(k = 0; k < 3; k++){
                printf("Enter the %d in x %d in y and %d in z element :" , i+1 , j+1 , k+1);
                scanf("%d",&arr[i][j][k]);
            }
        }
    }
    
    int pagefirst = 0;

    for(i = 0; i < 1; i++){
        for(j = 0; j < 3; j++){
            for(k = 0; k < 3; k++){
                pagefirst += arr[i][j][k];
            }
        }
    }
    
    int pagesecond = 0;

     for(i = 1; i < 2; i++){
        for(j = 0; j < 3; j++){
            for(k = 0; k < 3; k++){
                pagesecond += arr[i][j][k];
            }
        }
    }
    printf("the sum of first layer is : %d \n", pagefirst);
    printf("the sum of second layer is : %d \n", pagesecond);

    return 0;
}