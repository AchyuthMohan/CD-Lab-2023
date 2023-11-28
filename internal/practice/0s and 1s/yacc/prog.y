%{
#include<stdio.h>
#include<stdlib.h>    
%}

%token ZERO ONE
%%
stmt: ZERO ANY ZERO | ONE ANY ONE
ANY: ANY ZERO|ANY ONE |ZERO|ONE
%%

int main(){
    printf("Enter the input: \n");
    yyparse();
    printf("Accepted\n");
    return 0;
}

int yyerror(){
    printf("rejected\n");
    exit(0);
}