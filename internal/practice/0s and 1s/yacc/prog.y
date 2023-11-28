%{
#include<stdio.h>
#include<stdlib.h>    
%}

%token ZERO ONE ANY
%%
stmt: ZERO ANY ZERO | ONE ANY ONE
%%

int main(){
    printf("Enter the input: \n");
    yyparse();
    printf("Accepted");
    return 0;
}

int yyerror(){
    printf("rejected");
    exit(0);
}