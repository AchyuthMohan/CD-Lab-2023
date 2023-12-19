%{
#include<stdio.h>
#include<stdlib.h>    
#include<string.h>

%}

%token DO OPENCURLY LETTER OP CLOSECURLY WHILE OPENPAREN LT NUMBER CLOSEPAREN SC
%%
Expression: E {
    printf("Matched");
    return 0;
};

E: DO OPENCURLY LETTER OP OP CLOSECURLY
;


%%

int main(){
    printf("Enter the expresion: ");
    yyparse();
    return 0;
}

int yyerror(){
    printf("Un match");
    exit(1);
}