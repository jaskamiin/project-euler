/*
	Project Euler
	Problem #: 5
	
	Author:
		Jaska
	Description:
		This program will find the smallest possible number divisible by
		all numbers 1-20
*/

#include <stdio.h>

#include <stdio.h>

int main(){
    int i, j;

    for(i=1; i; ++i)
        for(j = 1; j < 21; ++j)
            if(!(i%j)) break;
            else if (j == 20) goto outer;

    outer: printf("%d\n", i);
    return 0;
}