#include<stdio.h>

int main(){
    int a , i;
    printf("Enter any numebr :");
    scanf("%d",&a);

    if (a%2==0)
        a-=1;
    
    for (i = a; i > 0 ; i--){
        printf(" %d ",i);
    }

    return 0;
}