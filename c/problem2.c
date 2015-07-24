/*
	Project Euler
	Problem #: 2
	
	Author:
		Jaska
	Description:
		This program will find the sum of all even numbers in
		the Fibonacci Sequence up to a given X.
*/

#include <stdio.h>

int fib(int);

int main(){
	printf("%d\n",fib(4000000));
	return 0;
}

int fib(int x){
	int i = 1, j = 2, k = i+j, sum = 2;
	
	while(k < x){
		if(k%2 == 0) sum += k;	
		i 	= j;
		j 	= k;	
		k 	= i+j;
	}
	
	return sum;
}