#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<string.h>
#include"header.h"

void Error(int E_Type,int Sign,char input){
	switch(E_Type){
		case 0:
			printf("Too Many Arguements. Arguement Cnt:%d\n",Sign);
			break;
		case 1:
			printf("Input Format Error\n");
			break;
		case 2:
			printf("Data Type Option '%c' does not exist\n",input);
			break;
		case 3:
			printf("Sort Method Option '%c' does not exist\n",input);
			break;
		case 4:
			printf("Data Option has been reassigned abnormally during process. Data Option: %d\n",Sign);
			break;
		case 5:
			printf("File location does not exist or unsucessfully located\n");
			break;
		case 6:
			printf("Sorting Method Option has been reassigned abnormally during process. Sorting Method Option: %d\n",Sign);
			break;
		case 7:
			printf("File location 'Manual.txt' does not exist or unsucessfully located\n");
			break;
		default:
			printf("Unkown Error occured\n");
			break;
	}
}

void Print_HManual(){
	FILE *fptr = fopen("Manual.txt","r");
	
	if(fptr == NULL){
		Error(7,0,0);
		exit(0);
	}

	char c;

	while(c!=EOF){
		c = fgetc(fptr);
		printf("%c",c);
	}

	fclose(fptr);
}

int Frt_Def(char *para,int Def){
	int Type;
	if(*para == '-'){
		char c = *(para+1);
		switch(c){
			case 'h':
				Print_HManual();
				exit(0);
			case 'n':
				Type = Numbers;
				break;
			case 's':
				Type = Strings;
				break;
			default:
				printf("Error at switch func in Func Frt_Def in header.c\n");
				Error(2,0,c);
				exit(0);
		}
	}
	else if(*para == 'x'){
		return Def;
	}
	else{
		printf("Error in Func Frt_Def in header.c\n");
		Error(1,0,0);
		exit(0);
	}
	
	return Type;
}

int Scd_Def(char *para,int Def){
	int Method;
	if(*para == '-'){
		char c = *(para+1);
		switch(c){
			case 'b':
				Method = BubbleSort;
				break;
			case 'i':
				Method = InsertionSort;
				break;
			case 's':
				Method = SelectionSort;
				break;
			default:
				printf("Error found at switch function in Scd_Def in header.c\n");
				Error(3,0,c);
				exit(0);
		}
	}
	else if(*para == 'x'){
		return Def;
	}
	else{
		printf("Error at Func Scd_DEf in header.c\n");
		Error(1,0,0);
		exit(0);
	}

	return Method;
}

void Print_Time(struct timeval start,struct timeval end){
	unsigned long diff;
	diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("Sorting performance: %ld us (equal to %lf sec)\n",diff,diff/1000000.0);
}

void Swap_N(int *first,int*second){
	int temp = *second;
	*second = *first;
	*first = temp;
}

void Swap_S(char *first,char *second){
	char *temp = (char*) malloc (sizeof(char*) *(MaxStrLen+1));
	strcpy(temp,second);
	strcpy(second,first);
	strcpy(first,temp);
	free(temp);
}

void Read_Num(FILE *fptr,int *nums){
	if(fptr!=NULL){
		for(int i=0; i<DataCnt; i++){
			fscanf(fptr,"%d\n",(nums+i));
		}
	}
	else{
		Error(5,0,0);
		exit(0);
	}
}

void Read_Str(FILE *fptr,char **strs){
	if(fptr != NULL){
		for(int i=0; i<DataCnt; i++){

			*(strs+i) = (char*) malloc (sizeof(char) * (MaxStrLen +2));
			fscanf(fptr,"%s\n",*(strs+i));
			char *p = (*(strs+i) + MaxStrLen);
			if(*p == '\n'){
				*p = '\0';
			}
		}
	}
	else{
		Error(5,0,0);
		exit(0);
	}
}

void Sort (int data_type,int sort_method){
	struct timeval start;
	struct timeval end;
	FILE *fptr;
	int *NumList = (int*) malloc (sizeof(int) *(DataCnt+2));
	char **StrList = (char**) malloc (sizeof(char*) * DataCnt);
	if(data_type == 0){
		fptr = fopen("dataset1.txt","r");
		rewind(fptr);
		Read_Num(fptr,NumList);
	}
	else if(data_type == 1){
		fptr = fopen("dataset2.txt","r");
		Read_Str(fptr,StrList);
	}
	else{
		Error(4,data_type,0);
		exit(0);
	}
	
	gettimeofday(&start,NULL);

	switch(sort_method){
			case 0:
				B_Sort(NumList,StrList,data_type);
				break;
			case 1:	
				I_Sort(NumList,StrList,data_type);
				break;
			case 2:
				S_Sort(NumList,StrList,data_type);
				break;
			default:
				Error(6,sort_method,0);
				break;
	}
	gettimeofday(&end,NULL);

	if(data_type == 0){
		freopen("dataset1_com.txt","w+",fptr);
		for(int i=0; i<DataCnt;i++){
			fprintf(fptr,"%d\n",*(NumList+i));
		}
	}
	else if(data_type == 1){
		freopen("dataset2_com.txt","w+",fptr);
		for(int i=0; i<DataCnt;i++){
			fprintf(fptr,"%s\n",*(StrList+i));
			free(*(StrList+i));
		}
	}
	else{
		Error(4,data_type,0);
		exit(0);
	}
	
	fclose(fptr);
	Print_Time(start,end);
	
	free(NumList);
	free(StrList);
}
