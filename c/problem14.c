#include <stdio.h>

int main(){
	unsigned int max=0, chainMax=0, high, i, x;
	
	for(i=0;i<1000000;i++){
		x = i;
		while(x!=1&&x!=0){
		//	x=!(x&1)?x/2:(x*3)+1;		//bit arithmetic method
			x=x%2?(x*3)+1:x/2;			//mod method
			max++;
		}	
		if(max>chainMax){
			chainMax = max;
			high = i;
		}
		max^=max;
	}
	
	printf("%d\n", high);
	return 0;
}