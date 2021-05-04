#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"

void I_Sort(int *nums,char ** strs,int Type){
	int i,j;
	unsigned long long int CmpCnt = 0;
	unsigned long long int ArrAcs = 0;
	if(Type == 0){
		int temp;
		for(i=1; i < DataCnt; i++){
			temp = *(nums+i);
			ArrAcs +=1;
			j = i - 1;
			while((j>-1) && (*(nums+j)>temp)){
				*(nums+j+1) = *(nums+j);
				j--;
				CmpCnt +=1;
				ArrAcs +=3;
			}
			CmpCnt +=1;
			*(nums+j+1)=temp;
			ArrAcs +=2;

		}
	}
	else if(Type == 1){
		char *temp = (char*) malloc ( sizeof(char) *(MaxStrLen+1));
		for(i=1; i < DataCnt; i++){
			strcpy(temp,*(strs+i));
			ArrAcs +=2;
			j = i - 1;
			while((j>-1) && (strcmp(temp,*(strs+j)) > 0)){
				strcpy(*(strs+j+1),*(strs+j));
				j--;
				ArrAcs +=6;
				CmpCnt +=1;
			}
			CmpCnt +=1;
			strcpy(*(strs+j+1),temp);
			ArrAcs +=4;
		}
		free(temp);
	}
	else{
		Error(4,Type,0);
		exit(0);
	}

	printf("Total Comparison Made:\t%llu times\n",CmpCnt);
	printf("Total Array Accesses Made:\t%llu times\n",ArrAcs);
}

