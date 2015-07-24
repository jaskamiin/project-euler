/*
	Project Euler
	Problem #: 1
	
	Author:
		Jaska
	Description:
		This program will find the sum of all numbers which are multiples 
		of X or Y, until a given number Z.
*/

#include <stdio.h>

int sum(int, int, int);

int main(){
	printf("%d\n",sum(3,5,1000));
	return 0;
}

int sum(int first, int second, int until){
	int i, total = 0;
	for(i=0;i<until;++i)
		if(i%3==0|| i%5==0) 
			total += i;
	return total;
}