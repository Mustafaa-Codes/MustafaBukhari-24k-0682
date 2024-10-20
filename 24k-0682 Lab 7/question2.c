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
    int reverse[n];    
    int x=0;
    int j=0;
    for (x=n-1;x>=0;x--){
        reverse[j]=Array[x];
        j=j+1;
        
    }
    int a;
    for (a=0;a<n;a++){
        printf("%d",reverse[a]);
    }
}