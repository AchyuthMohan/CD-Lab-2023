%{
#include<stdio.h>
#include<stdlib.h>    
%}

%token HTTPS FC SLASH HOST PATH EQ 

%%
Expression: url {
printf("Accepted URL\n");
    return 0;
};

url:HTTPS FC SLASH SLASH HOST SLASH PATH SLASH PATH EQ PATH
%%

int main(){
    printf("Enter the url: ");
    yyparse();
    return 0;
}
int yyerror(){
    printf("URL is not accepted\n");
    return 1;
}