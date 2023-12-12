%{
#include<stdio.h>
#include<stdlib.h>    
%}

%token FOR OPEN LET EQ DIG LT SC OP CLOSE OPENCURL CLOSECURLY
%%
GivenExpression: L {
    printf("Success for loop");
    return 0;
};

L: FOR OPEN LET EQ DIG SC LET LT LET SC LET OP OP CLOSE DEF
DEF: OPENCURL LET CLOSECURLY


%%

int main(){
    printf("Enter the statement: ");
    yyparse();
    return 0;
}
int yyerror(){
    printf("Error in parsing..");
    exit(0);
}