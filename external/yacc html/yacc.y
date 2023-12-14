%{
#include<stdio.h>
#include<stdlib.h>    
%}

%token OPEN TAG CLOSE SLASH LETTER
%%
Expression: E {
    printf("Validated the Expression\n");
    return 0;
};

E: OPEN TAG CLOSE E OPEN SLASH TAG CLOSE
| LETTER
;
%%

int main(){
    printf("Enter the Expression: \n");
    yyparse();
    return 0;
}
int yyerror(){
    printf("No Match\n");
    return 1;
}
