#include <stdio.h>
#include <stdlib.h>
int main() {
int n;
struct StudentDetails{
  char StudentName[20];
  float StudentMarks;
};
float Total,Avg;
printf("Enter the total number of students in the class: \n");
scanf("%d",&n);
struct StudentDetails *p=(struct StudentDetails *)malloc(n*sizeof(struct StudentDetails));
if (p == NULL){
  printf("Error Allocating Memory!\n");
  return 1;
}
for (int i=0;i<n;i++){
  printf("Enter the name of the student: \n");
  scanf("%s",&p[i].StudentName);
  printf("Enter marks obtained: \n");
  scanf("%f",&p[i].StudentMarks);
  Total+=p[i].StudentMarks;
}
Avg=Total/n;
printf("The Class average is: %.2f",Avg);
free(p);
return 0;
}