/*
	Project Euler
	Problem #: 11
	
	Author:
		Jaska
	Description:
		This program will find the largest product of n consecutive
		numbers touching in any direction in a grid size X,Y
*/

#include <stdio.h>

#define GRID 1500
#define PRODUCTS 4
#define WIDTH 20
#define true 1
#define false 0

#define OFFSET(x,y) ((WIDTH*y)+x)

//function definitions
void	readFileToArray(int grid[GRID]);

typedef int bool;

int main(){
	int		grid[GRID], total, offset, highest, i=0, k, m;
	bool	toRight, toLeft, toUp, toDown;
	
	readFileToArray(grid);
	
	for(k=0;k<WIDTH;++k){
		for(m=0;m<WIDTH;++m){
		
		//set data
			offset=OFFSET(k,m);
		
		//assume all directions are false	
			toRight=toLeft=toUp=toDown=false;
			
		//check which directions can be tested	
			if(k<WIDTH-(PRODUCTS-1))	toRight = true;
			if(m<WIDTH-(PRODUCTS-1))	toDown	= true;
			if(k>(PRODUCTS-1))			toLeft	= true;
			if(m>(PRODUCTS-1))			toUp	= true;
			
		//calculate products	
			if(toRight){
				total=1;
				for(i=0;i<PRODUCTS;++i)	total*=grid[offset+i];
				if(total>highest) highest=total;
			}
			
			if(toLeft){
				total=1;
				for(i=0;i<PRODUCTS;++i) total*=grid[offset-i];
				if(total>highest) highest=total;
			}

			if(toUp){
				total=1;
				for(i=0;i<PRODUCTS;++i) total*=grid[offset-WIDTH*i];
				if(total>highest) highest=total;
			}

			if(toDown){
				total = 1;
				for(i=0;i<PRODUCTS;++i) total*=grid[offset+WIDTH*i];
				if(total>highest) highest=total;
			}
			
			if(toRight&&toUp){
				total=1;
				for(i=0;i<PRODUCTS;++i) total*=grid[offset-(WIDTH*i)+i];
				if(total>highest) highest=total;
			}
			
			if(toRight&&toDown){
				total=1;
				for(i=0;i<PRODUCTS;++i) total*=grid[offset+(WIDTH*i)+i];
				if(total>highest) highest=total;
			}
			
			if(toLeft&&toUp){
				total=1;
				for(i=0;i<PRODUCTS;++i) total*=grid[offset-(WIDTH*i)-i];
				if(total>highest) highest=total;	
			}	
			
			if(toLeft&&toDown){
				total=1;
				for(i=0;i<PRODUCTS;++i) total*=grid[offset+(WIDTH*i)-i];
				if(total>highest) highest=total;	
			}
		}
	}
	
	printf("%d\n",highest);
	return 0;
	
//	error:
//	printf("\noffset:\t%d\nxpos:\t%d\nypos:\t%d\ntotal:\t%d\noffset with highest:\t%d\n",offset,xpos,ypos,highest, save);
		
	
}

void readFileToArray(int grid[GRID]){
	FILE *fp;
	int i;
	
	if(NULL==(fp=fopen("../sources/files/p11grid.txt","r"))){
        perror("file can't open");
        return;
    }
    
	for(i=0;i<400;++i)
		fscanf(fp, "%d", &grid[i]);
	
	fclose(fp); 
}