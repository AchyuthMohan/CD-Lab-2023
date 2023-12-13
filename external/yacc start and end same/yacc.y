%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token ZERO ONE
%%
Expression: E {
    printf("Satifies the condition\n");
    return 0;
};
E: ZERO ANY ZERO
| ONE ANY ONE
;
ANY: ZERO
| ONE
| ANY ZERO
| ANY ONE
;

%%
int main(){
    printf("Enter the expression: ");
    yyparse();
    return 0;
}
int yyerror(){
    printf("No Match\n");
    return 1;
}