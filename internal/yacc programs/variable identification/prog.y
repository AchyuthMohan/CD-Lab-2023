%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token LET DIG
%%
var:var DIG
    |var LET
    | LET

%%

int main(){
    printf("Enter the identifier: \n");
    yyparse();
    printf("It is an identifier..\n");
    return 0;
}

int yyerror(){
    printf("Not an identifier\n");
    exit(0);
}