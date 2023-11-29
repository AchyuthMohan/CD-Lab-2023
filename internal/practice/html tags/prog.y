%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    int yyerror();
%}

%token OPEN CLOSE SLASH TAG LETTER
%%

stmt: OPEN TAG CLOSE CONTENT OPEN SLASH TAG CLOSE
CONTENT: LETTER | stmt stmt 
%%

int main(){
    printf("Enter the content: \n");
    yyparse();
    printf("valid\n");
    return 0;
}
int yyerror(){
    printf("Error\n");
    exit(1);
}