#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH   50
#define HEIGHT 100

void rev(char* str){
	int len = strlen(str), i=0;
	
	while(i < (len - i - 1)){
		str[i] ^= str[len - i - 1];
		str[len - i - 1] ^= str[i];
		str[i] ^= str[len - i - 1];
		i++;
	}
}	

void add(char* a, char* b/*, char* answer*/){
	int 	sum=0, carry=0, width=strlen(a)+1, i,j;
	char*	answer = malloc(width);
	
	for(i=0; i<width-1; i++){
		sum = (a[width-2-i]-48) + (b[width-2-i]-48) + carry;
		carry = 0;
		if(sum > 9){
			carry = 1;
			sum-=10;
		}
		answer[i] = sum+48;
	}
	
	if(carry) answer[i++] = carry+48;
	answer[i]= 0;	
	
	rev(answer);
	memcpy(a,answer,strlen(answer));
	a[strlen(a)+1] = 0;
	free(answer);
}

int main(){
	char	arr[HEIGHT][WIDTH+2], tempAns[WIDTH+1];	
	int 	i = 0, j = 0, size = 0, carry = 0;
	FILE	*fp = fopen("../sources/files/p13num.txt","r");
	
	if(!fp) return 1;

/*load array with numbers*/	
	do{
		while(fgets(arr[i],WIDTH+2,fp)){
			j=0;
			while(arr[i][j]!=0&&arr[i][j]!=0x0d)j++;
			arr[i][j]=0;
			i++;
		}	
	} while(!feof(fp));	
	
//set tempAns as all 0s	
	memset(tempAns,'0',WIDTH);
	tempAns[WIDTH] = 0;
	
	for(i=0;i<HEIGHT;i++){
		add(tempAns,arr[i]);
		printf("%i:\t%s\n",i,tempAns);	
	}

/*Finish*/	
	FILE *ofp = fopen("../sources/files/13out.txt","w");
	if(ofp) fprintf(ofp,"%s", arr[i]);
	
	fclose(fp);
	fclose(ofp);
	return 0;
}