%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
void yyerror(const char *);

%}

%token OPEN CLOSE  TAG SLASH LETTER

%%

stmt: OPEN TAG CLOSE CONTENT OPEN SLASH TAG CLOSE 
CONTENT: stmt stmt | LETTER

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
