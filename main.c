#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<string.h>
#include"header.h"


int main(int argc,char **argv){
	int Data_Type = 0;
	int Sort_Method = 0;
	char *Frt_P = (char*) malloc (sizeof(char) *3);
	char *Scd_P = (char*) malloc (sizeof(char)*3);
	if(argc == 1){
		*Frt_P = 'x';
		*Scd_P = 'x';
	}
	else if(argc >1 && argc <= 3){
		strcpy(Frt_P,*(argv+1));
		if(argc == 3){
			strcpy(Scd_P,*(argv+2));
		}
		else{
			*Scd_P = 'x';
		}
	}
	else{
		printf("Error at main.c\n");
		Error(0,argc,0);
	}
	Data_Type = Frt_Def(Frt_P,Data_Type);

	Sort_Method = Scd_Def(Scd_P,Data_Type);

	Prod_Data(Data_Type);
	
	Sort(Data_Type,Sort_Method);
	
	free(Frt_P);
	free(Scd_P);
	return 0 ;
}
