#include <stdio.h>
#include <stdlib.h>
int main(){
    int m,n;
    printf("enter array dimensions: \n");
    printf("Amount of rows= ");
    scanf("%d",&m);
    printf("Amount of cols= ");
    scanf("%d",&n);
    int **mat1=(int **)malloc(m*sizeof(int *));
    int **mat2=(int **)malloc(m*sizeof(int *));
    int **result=(int **)malloc(m*sizeof(int *));
    for (int i=0;i<n;i++){    
        mat1[i]=(int *)malloc(n*sizeof(int));
        mat2[i]=(int *)malloc(n*sizeof(int));
        result[i]=(int *)malloc(m*sizeof(int));
    }
    printf("Enter Matrice 1 elements: \n");
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            scanf("%d",&mat1[i][j]);
    }
    }
    printf("Enter Matrice 2 elements: \n");
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            scanf("%d",&mat2[i][j]);
        }
    }
     for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                result[i][j]=+mat1[i][k]*mat2[k][j];
            }
        }
     }
     printf("The result matrice is:\n"); 
      for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            printf("%d",result[i][j]);
        }
        printf("\n");
      }
    return 0;
}

