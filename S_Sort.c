#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"

void S_Sort(int *nums,char **strs,int Type){
	int i,j;
	unsigned long long int CmpCnt = 0;
	unsigned long long int ArrAcs = 0;
	if(Type == 0){
		int index;
		for(i=0; i<DataCnt; i++){
			index=i;
			for(j=i+1; j<DataCnt; j++){
				if(*(nums+j) < *(nums+index)){
					index=j;
				}	
				ArrAcs +=2;
				CmpCnt +=1;
			}
			Swap_N(nums+i,nums+index);
			ArrAcs +=4;
		}
	}
	else if(Type == 1){
		char *index;
		for(i=0; i<DataCnt; i++){
			index = *(strs+i);
			ArrAcs +=1;
			for(j=i+1; j<DataCnt; j++){
				if(strcmp(index,*(strs+j)) < 0 ){
					index = *(strs+j);
					ArrAcs +=2;
				}
				CmpCnt +=1;
				ArrAcs +=3;
			}
			Swap_S(*(strs+i),index);
			ArrAcs +=12;
		}
	}
	else{
		Error(4,Type,0);
		exit(0);
	}
	printf("Total Comparison Made:\t%llu times\n",CmpCnt);
	printf("Total Array Accesses Made:\t%llu times\n",ArrAcs);

}
