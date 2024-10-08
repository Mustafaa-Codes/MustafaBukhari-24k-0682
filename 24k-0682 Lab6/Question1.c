#include <stdio.h>
int main(){
	int sum;
	sum=0;
	int num;
	printf("Enter a number:\n");
	while(num!=0){
		scanf("%d\n",&num);
		printf("Your Number is: %d\n",num);
		sum=sum+num;
		printf("Your sum is: %d\n",sum);
	}
	return 0;
}
