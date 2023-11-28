%{
#include<stdio.h>
#include<stdlib.h>    
%}

%%
0[01]*0 {printf("Valid\n");}
1[01]*1 {printf("Valid\n");}
1[01]*0 {printf("InValid\n");}
0[01]*1 {printf("InValid\n");}
%%
int main(){
    printf("Enter the expression: \n");
    yylex();
}