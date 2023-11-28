%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
void yyerror(const char *);

%}

%token OPEN CLOSE CONTENT

%%

stmt: OPEN stmt CLOSE | CONTENT

%%

int main() {
    printf("Enter the statement: \n");
    yyparse();
    printf("Valid\n");
    return 0;
}

void yyerror(const char *s) {
    printf("Invalid: %s\n", s);
    exit(1);
}
