/*
	Project Euler
	Problem #: 6
	
	Author:
		Jaska
	Description:
		This program will find the difference between the sum of the squares
		and square of the sums of all numbers k to n.
*/

#include <stdio.h>

int main(){
	int sumOS = 0, sqOS = 0, i;
	
	for(i = 1; i < 101; ++i){
		sumOS += i*i;
		sqOS += i;
	}
	printf("%d\n", (sqOS * sqOS)-sumOS);
	return 0;
}