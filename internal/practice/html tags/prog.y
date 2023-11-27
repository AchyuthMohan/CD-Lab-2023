%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
void yyerror(const char *);

%}

%token OPEN_HTML CLOSE_HTML OPEN_BODY CLOSE_BODY OPEN_HEAD CLOSE_HEAD OPEN_P CLOSE_P CONTENT

%%

stmt: OPEN_HTML stmt CLOSE_HTML
    | OPEN_BODY stmt CLOSE_BODY
    | OPEN_HEAD stmt CLOSE_HEAD
    | OPEN_P stmt CLOSE_P
    | CONTENT
    ;

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
