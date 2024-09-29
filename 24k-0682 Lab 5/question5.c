/*
 * Name: Mustafa Bukhari
 * Roll#: 24k-0682
 * Desc: Question 5 Lab 5
*/
#include <stdio.h>
int main () {
	char key;
	key=42;
	char character;
	char decryptedkey;
	char encryptedkey;
	printf("Enter Key to encrypt\n");
	scanf("%c",&character);
	encryptedkey=character^key;
	printf("Result after encryption: %c\n",encryptedkey);
	decryptedkey=encryptedkey^key;
	printf("Result after dencryption: %c\n",decryptedkey);
}