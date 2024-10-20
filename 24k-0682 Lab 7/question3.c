#include <stdio.h>
int main() {
    int n;
    printf("enter array length: ");
    scanf("%d",&n);
    int Array[n];
    for(int y=0; y<n;y++){
        printf("enter element %d: ",y);
        scanf("%d",&Array[y]);
    }
    int max=Array[0],min=Array[0];
    for(int x=1;x<n;x++){
        if (Array[x]>max){
            max=Array[x];
        } 
        }
    
    for(int j=1;j<n;j++){
        if (Array[j]<min){
            min=Array[j];
        } 
    }
    printf("max is %d\n",max);
    printf("min is %d",min);
}