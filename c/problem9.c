/*
	Project Euler
	Problem #: 9
	
	Author:
		Jaska
	Description:
		This program will find the Pythagorean triplet for which 
		a + b + c = n.
*/

#include <stdio.h>

int main(){
	
	int a, b, c;
	
	for(a=1;a<1000;++a)
		for(b=1;b<1000;++b)
			for(c=1;c<1000;++c){
				if((a*a)+(b*b)==(c*c)&&(a+b+c)==1000)goto outer;
			}

	outer:
		printf("%d + %d + %d = %d\n", a,b,c, a+b+c);
		printf("%d x %d x %d = %d\n", a,b,c, a*b*c);
		
	return 0;
}