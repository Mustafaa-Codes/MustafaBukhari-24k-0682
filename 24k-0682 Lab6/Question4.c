#include <stdio.h>
int main(){
	int i;
	i=2;
	int product;
	product=2;
	printf("%d ",i);
	for (i=2 ; i<=8;i++){
		product=product*(i/2);
		printf("%d ",product);
		
	}
	return 0;
	
}
