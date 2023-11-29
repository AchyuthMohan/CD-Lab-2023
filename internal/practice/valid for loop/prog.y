%{
#include<stdio.h>    
#include<stdlib.h>
int valid=1;

%}

%token FOR LPAREN DATATYPE EQ ID OP NUMBER SC  COMP RPAREN RCURLY LCURLY

%%
STMT:FOR LPAREN DATATYPE ID EQ NUMBER SC ID COMP NUMBER SC ID OP OP RPAREN LCURLY BODY RCURLY
BODY: STMT | ID EQ ID
;
%%


int yyerror(){
    printf("UN Matched");
    valid=0;
    return 0;
}

int main(){
    printf("Enter the statement :\n");
    yyparse();
    if(valid){
        printf("Matched..\n");
    }
    
    return 0;
}
