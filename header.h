#ifndef HEADER_H
#define HEADER_H

#define DataCnt 1000000
#define MaxStrLen 100

#define Numbers 0
#define Strings 1

#define BubbleSort 0
#define InsertionSort 1
#define SelectionSort 2

void Print_HManual();

void Error(int E_Type,int Sign,char input);

int Frt_Def(char *para,int Def);

int Scd_Def(char *para,int Def);

void Prod_Num (FILE *fptr);

void Prod_Str (FILE *fptr);

void Prod_Data(int Type);

void Swap_N(int *first,int *second);

void Swap_S(char *first,char *second);

void Read_Num(FILE *fptr,int *nums);

void Read_Str(FILE *fptr,char **strs);

void B_Sort(int *nums,char **strs,int Type);

void I_Sort(int *nums,char **strs,int Type);

void S_Sort(int *nums,char **strs,int Type);

void Sort(int data_type,int sort_method);

#endif
