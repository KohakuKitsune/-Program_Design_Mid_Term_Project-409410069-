#include<stdio.h>
#include<stdlib.h>
#include"header.h"

void Prod_Num (FILE* fptr){
	srand(1);

	for(int i = 0; i < DataCnt; i++){
		fprintf(fptr,"%d\n",rand()%10);
	}
}

void Prod_Str (FILE* fptr){
	srand(1);
	char c;
	for(int i = 0; i < DataCnt; i++){
		for(int j = 0; j < MaxStrLen; j++){
			c = 65 + (32 *(rand()%2)) + rand()%23;
			fprintf(fptr,"%c",c);
		}
		fprintf(fptr,"\n");
	}
}

void Prod_Data(int Type){
	FILE *fptr;
	if(Type == 0){
		fptr = fopen("dataset1.txt","w+");
		Prod_Num(fptr);
	}
	else if(Type == 1){
		fptr = fopen("dataset2.txt","w+");
		Prod_Str(fptr);
	}
	else{
		Error(4,Type,0);
		exit(0);
	}
	fclose(fptr);
}
