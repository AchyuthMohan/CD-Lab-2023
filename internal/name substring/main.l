%{
#include<stdio.h>
#include<stdlib.h>
FILE *fp;    
%}
%%
[a-zA-Z]*"achy"[a-zA-Z]* { }
%%
int main(){
    fp=fopen("input.txt","r");
    if(fp==NULL){
        printf("Error in file");
        exit(0);
    }
    yyin=fp;
    yylex();
    fclose(fp);
}