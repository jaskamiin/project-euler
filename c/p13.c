#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define numOfDecimals 55

typedef struct {
	unsigned char decimals[numOfDecimals];
	int order;
//	int negative;
} bignum;
	
void bignum_init(bignum *number){
//	number->negative=0;
	number->order=1;
	memset(number->decimals, 0 ,sizeof(number->decimals));
}

int bignum_add(bignum *b, bignum *a){
	unsigned char reminder=0;
	int i= a->order > b->order ? a->order:b->order,j=0;
	
	while(j<i||reminder>0){
		b->decimals[j]+=reminder+a->decimals[j];
		if(b->decimals[j] > 9 ){
			b->decimals[j]-=10;
			reminder=1;
		} else reminder=0;
		j++;
	}
	
	b->order=j;
	return j;
}

int bignum_convert(bignum *a, const char *str){
	int len=strlen(str),i,j=0;
	while(len>0 && (str[len-1]<'0'|| str[len-1]>'9')) len--; //skip CR LF, if they are present;
	for(i=len-1;i>=0;i--){
		if(str[i] <'0'|| str[i] >'9') break;
		a->decimals[j++]=str[i]-'0';
	}
	a->order=j;
	return j;
}

void bignum_print(bignum *number){
	int i;
	for(i=number->order-1;i>=0;i--) printf("%c",number->decimals[i]+'0');
}


int main(){
	char str[100];
	bignum a,sum;
	bignum_init(&a);
	bignum_init(&sum);
	FILE *input;
	input=fopen("../sources/files/p13num.txt","r");
	if(input==NULL) {
		printf("can't open the file\n");
		exit(1);
	}
	while(fgets(str,sizeof(str),input)){
		bignum_convert(&a,str);
		bignum_add(&sum,&a);
	}
	
	bignum_print(&sum);
	printf("\n");

	fclose(input);
	return 0;
}


