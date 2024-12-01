#include <stdio.h>
#include <stdlib.h>
int main(){
    int sum,n;
    sum=0;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    int *p=(int *)malloc(n*sizeof(int));
    if (p==NULL){
        printf("Memory Allocation failed\n");
        return 1;
    }
    printf("Enter array elements: \n");
    for (int i=0;i<n;i++){
        scanf("%d",&p[i]);
        sum+=p[i];
    }
    printf("%d",sum);
    free(p);
    return 0;
}

