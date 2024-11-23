#include <stdio.h>
int main(){
    const int Maxtemp=80;
    static int sum = 0;
    int temp=0;
    for (int x=0;x<=3;x++){
        printf("Write the Temperature to compare.\n");
        scanf("%d",&temp);
        if (temp>Maxtemp){
            sum++;
            printf("Temperature exceeds the Maximum Temperature.\n");
        }
        else{
            printf("Temperature does not exceed the Maximum Temperature.\n");
        }
    }
    printf("The total amount of times the temperature exceeded the max temperature is :%d",sum);
}