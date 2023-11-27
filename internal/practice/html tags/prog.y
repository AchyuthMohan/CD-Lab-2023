%{
#include<stdio.h>
#include<stdlib.h>    
%}

%token LET CONT
%%
stmt: OPEN stmt CLOSE | LET
OPEN: '<' CONT '>'
CLOSE: '<' CONT '>'
%%

int main(){
    printf("Enter the statement: \n");
    yyparse();
    printf("Valid");
    return 0;
}

int yyerror(){
    printf("Un matched ");
    exit(0);
}