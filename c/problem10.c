/*
	Project Euler
	Problem #: 10
	
	Author:
		Jaska
	Description:
		This program will find the sum of all primes < n.
*/

#include <stdio.h>
#include <math.h>

static inline int isPrime(int x);

int main(){
	typedef unsigned long long llong;
	int i;
	llong s = 2;
	for(i = 3; i < 2000000; i+=2)if(isPrime(i))s+=i;
	printf("%lld\n", s);
	return 0;

 return(0);
}

static inline int isPrime(int x){
	int i, n = ceil(sqrt(x));
	if(x==2||x==3) 					return 1;				//if i = 2 or 3, return true
	if(!(x&1)||x==0||x==1)			return 0;				//if x is even  return false
	for(i=3;i<=n;i+=2)if (x%i == 0) return 0;				//if x is divisible by i return false
	return 1;
}