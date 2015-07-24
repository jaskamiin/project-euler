/*
	Project Euler
	Problem #: 8
	
	Author:
		Jaska
	Description:
		This program will find the largest product of n consecutive
		digits in a given number.
*/

#include <stdio.h>
#define STR_BUF 1500

void read_file(char*);
int strsize(char*);

int main(){
	char number[STR_BUF];
	int i,j, product, k = 0;
	read_file(number);
	
	for(i^=i; i<strsize(number)-4; ++i){
		product = 1;
		for( j^=j; j<5; ++j) product *= (number[i+j]-48);
		k=product>k?product:k;
	}
	
	printf("%d\n", k);
	return 0;
}

void read_file(char* string){
	FILE *fp;
	fp = fopen("../sources/files/p8num.txt", "r");  
	
	if (fp){ 
		fgets(string, STR_BUF, fp); 
		string[strsize(string)] = 0;
	}
	
	fclose(fp); 
}

int strsize(char* str){
	int i = 0;
	while(str[i] != '\0') ++i;
	return i;
}