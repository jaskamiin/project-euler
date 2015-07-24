/*
	Project Euler
	Problem #: 12
	
	Author:
		Jaska
	Description:
		This program will find the value of the first 
		triangle number to have over five hundred divisors.
*/

#include<stdio.h>

int main(){
	long i,j,factors=0,num=1;
	for(i=2;factors<500;i++){			
		factors=0;						
		for(j=1;j<=num/2;j++)
			if(num%j==0) factors++;				
		num+=i;							
	}
	printf("%d\n",num);
	return 0;
}



