%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token DIG LET

%%
var: LET | var LET | var DIG
%%

int main(){
    printf("Enter the var name: \n");
    yyparse();
    printf("Accepted..");
    return 0;
}
int yyerror(){
    printf("not Accepted");
    exit(0);
}