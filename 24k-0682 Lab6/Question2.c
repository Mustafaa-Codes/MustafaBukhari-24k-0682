#include <stdio.h>
int main() {
	int i;
	int a;
	a=0;
	i=1;
	int Number;
	int num;
	int x;
	x=1;
	while (x!=0) {
	printf("enter num: ");
	scanf("%d", &num);
	x = num/10;
	if(x!=0){
		printf("%d is multiple digit \n",num);
		x=0;
	} else {
		printf("%d is not multiple digit",num);
	}
	}
	for( i=1;i<=num;i++)
	{
		if(num%i==0)
	{
		a++;
		break;
	}
	}

if( a==2){
	printf("It is a prime number");
}
else{
	printf("It is a composite number");
}
}
		
	

