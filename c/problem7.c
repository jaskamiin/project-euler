/*
	Project Euler
	Problem #: 7
	
	Author:
		Jaska
	Description:
		This program will find the n prime number.
*/

#include <stdio.h>
#include <math.h>

int isPrime(int);

int main(){
	int c,t=0;
	for(c=0;c<=10001;t++){
		if(isPrime(t))++c;
		if(c == 10001) break;
	}
	
//	for(c=0;c<=10001;t++) isPrime(t)?{c!=10001?++c:break}:continue;
	
	printf("%d\n", t);
	return 0;
}

int isPrime(int x){
	int i, n = ceil(sqrt(x));
	if(x==2||x==3) 			return 1;				//if i = 2 or 3, return true
	if(!(x&1)||x==0||x==1)	return 0;				//if x is even  return false
	for(i=3;i<=n;i+=2)if (x%i == 0) return 0;		//if x is divisible by im return false
	return 1;
}