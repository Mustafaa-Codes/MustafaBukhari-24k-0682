#include<stdio.h>
int main(){

    int start , end , a , b , isprime = 1 ;

    printf("Enter the starting number: \n");
    scanf("%d",&start);

    printf("Enter the ending number: \n");
    scanf("%d",&end);

    for(a = start ; a <= end; a++){
        if(a == 2){
            printf(" %d ", a);
        }
        for(b = 2; b < a; b++){
            isprime=1;
            if(a%b == 0){
                isprime = 0;
                break;
            }
        }
        if(isprime == 1){
            printf(" %d ", a);
        } 
    }

    return 0;
}