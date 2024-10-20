#include <stdio.h>
int main() {
    int n;
    printf("enter length of array: ");
    scanf("%d",&n);
    int Array[n];
    for(int y=0; y<n;y++){
        printf("enter element %d: ",y);
        scanf("%d",&Array[y]);
    }
    int sum=0;
    for (int x=0;x<n;x++){
        sum=sum+Array[x];
    }
    printf("%d",sum);
}