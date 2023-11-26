%{
    #include<stdio.h>
    #include<stdlib.h>
%}
%token DIG LET

%%

var: var DIG | var LET | LET ;

%%
int main(){
    printf("Enter the variable \n");
    yyparse();
    printf("It is a valid variable\n");
    return 0;
}
int yyerror(){
    printf("It is an invalid variable\n");
    exit(0);
}