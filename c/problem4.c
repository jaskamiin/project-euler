/*
	Project Euler
	Problem #: 4
	
	Author:
		Jaska
	Description:
		This program will find the largest palindromic number that
		is a product of two three-digit numbers.
*/

#include <stdio.h>
#define STR_BUF 255

void intToString(int, char*);
int size(char*);
int isPalindrome(int);
int lrgPldrm();

int main(){
	printf("%d", lrgPldrm());
	return 0;
}

void intToString(int x, char* str){
	sprintf(str,"%d", x);
}

int size(char* str){
	int i = 0;
	while (str[i] != '\0') ++i;
	return i;
}

int isPalindrome(int x){
	int i = 0, len=0;
	char str[STR_BUF] = "";
	
//convert number to check into a string	and find it's length
	intToString(x, str);
	len = size(str);

//while str[i] and str[len-i-1] don't cross, check if they match. If not, it's not a palindrome.	
	for(i = 0; i < len-i -1; ++i) if (str[i] != str[len-i-1]) return 0;
	
	return 1;
}

int lrgPldrm(){
	int x = 100, y = 100, k = 0;
	
	for(x = 100; x < 1000; ++x)
		for (y = 100; y < 1000; ++y)
			if (isPalindrome(x*y) && (x*y)> k) k = x*y;
			
	return k;		
	
}