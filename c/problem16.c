#include <stdio.h>
#include <string.h>

#define STR_BUF 500

void rev(char* str){
	int len = strlen(str), i=0;
	
	while(i < (len - i - 1)){
		str[i] ^= str[len - i - 1];
		str[len - i - 1] ^= str[i];
		str[i] ^= str[len - i - 1];
		i++;
	}
}

void square(char* a){
	int i, j, length=strlen(a), sum, carry = 0;
	char answer[STR_BUF];
	
	memset(answer,'0',STR_BUF);
	
	for(i=0;i<length-1;i++){
		sum 	= (a[length-1-i]-48) + (a[length-1-i]-48) + carry;
		carry 	= 0;
		if(sum > 9){
			carry = 1;
			sum -= 10;
		}
		answer[i] = sum+48;
	}
		
	if(carry) answer[i++] = carry+48;
	answer[i+1] = 0;
	
	rev(answer);
	memcpy(a, answer, strlen(answer));
	a[strlen(a)] = 0;
}

int main(){
	int 	i, sum=0;
	char 	number[STR_BUF];
	
	memset(number,'0',STR_BUF);	number[STR_BUF]	=0;
	number[STR_BUF-1] 	= '2';
	

	for(i=0;i<999;i++)
		square(number);
	
	for(i=0;i<STR_BUF;i++)
		 sum+=number[i]-'0';
		 
	printf("%d\n",sum);	
	return 0;
}