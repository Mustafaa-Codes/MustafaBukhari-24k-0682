#include <stdio.h>
int main() {
	int x=1,y=2;
	int product;
	printf("%d %d ",x,y);
	while (product!=2097152) {
		product=x*y;
		printf("%d ",product);
		x=y;
		y=product;
	}
}