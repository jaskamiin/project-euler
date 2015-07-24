/*
	Project Euler
	Problem #: 3
	
	Author:
		Jaska
	Description:
		This program will find the largest prime number in a given number X
*/

#include <stdio.h>
#include <math.h>
#include <inttypes.h>

uintmax_t isPrime(uintmax_t);
uintmax_t highestPrime(uintmax_t);

int main(){
	printf("%d\n", highestPrime(600851475143));
	return 0;
}

uintmax_t isPrime(uintmax_t x){
	uintmax_t i = 2;
	if(x == i++) 		return 1;	//if i = 2, return true
	if(x == i)			return 1;	//if i = 3, return true
	if(!(x&1)||x%i==0) 	return 0;	//otherwise, if x is even or divisible by 3, return false
		
	for(i=3; i<=sqrt(x); i+=2)	
		if (x%i == 0) return 0;		//if x is divisible by im return false

	return 1;
}

uintmax_t highestPrime(uintmax_t x){
	uintmax_t i, k = 0, y;
	
	if (isPrime(x)) return x;

	for (i = 2; i < x+1; i++){
	
		if(isPrime(i)&&x%i==0) x/=i;
		else continue;
	
		if (i > k) k = i;
		i = 2;
	}
	
	return k;
}