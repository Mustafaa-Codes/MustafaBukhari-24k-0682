#include<stdio.h>

int main(){

    int a , space  , diamond = 1;

    printf("Enter any number :");
    scanf("%d",&a);

    space = ((a*2)- 1)/2;

    for(int i = 0; i < a;  i++){
        for(int j = 0; j < space; j++){
            printf(" ");
        }
        for(int k = 0; k < diamond; k++){
            printf("*");
        }
        printf("\n");

        space--;
        diamond=diamond+2;
    }

    space=1 , diamond= a*2 - 3;

    for(int i = 0; i < a-1;  i++){
        for(int j = 0; j < space; j++){
            printf(" ");
        }
        for(int k = 0; k < diamond; k++){
            printf("*");
        }

        printf("\n");

        space++;
        diamond=diamond-2;
    }

    return 0;
}