#include <stdio.h>
int main(){
	int i;
	int myNumbers[] = {65536, 32768, 10922, 2730, 546, 91, 13, 1, 0};
	for (i=0 ; i<=8;i++){
		printf("%d ", myNumbers[i]);
	}
	return 0;
	
}
