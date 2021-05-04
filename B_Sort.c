#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"

void B_Sort(int *nums,char **strs,int Type){
	int i,j;
	unsigned long long int CmpCnt = 0;
	unsigned long long int ArrAcs = 0;
	if(Type == 0){
		for(i=0; i < DataCnt-1; i++){
			for(j=0; j < DataCnt-1-i; j++){
				if(*(nums+j) > *(nums+j+1)){
					Swap_N(nums+j,nums+j+1);
					ArrAcs +=4;
				}
				CmpCnt +=1;
				ArrAcs +=2;

			}
		}
	}
	else if(Type == 1){
		for(i=0; i< DataCnt - 1; i++){
			for(j=0; j < DataCnt -1 - i; j++){
				if(strcmp(*(strs+j),*(strs+j+1)) > 0){
					Swap_S(*(strs+j),*(strs+j+1));
					ArrAcs +=8;
				}
				CmpCnt +=1;
				ArrAcs +=4;
			}
		}
	 }
	else{
		Error(4,Type,0);
		exit(0);
	}

	printf("Total Comparison Made:\t%llu times\n",CmpCnt);
	printf("Total Array Accesses Made:\t%llu times\n",ArrAcs);
}
