%{
#include<stdio.h>
#include<stdlib.h>    
%}
%token DIG LET FOR

%%
stmt: FOR '(' INIT ';' COND ';' ')'
INIT: LET '=' DIG
COND: LET '<' LET | LET '>' LET


%%
int main(){
    printf("Enter the loop: \n");
    yyparse();
    printf("Valid for loop\n");
    return 0;
}
int yyerror(){
    printf("un matched..\n");
    exit(0);
}