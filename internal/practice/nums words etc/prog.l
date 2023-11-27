%{
#include<stdio.h>  
%}
%%
if |
else |
printf |
for |
main    {printf("Keyword %s\n",yytext);}

[0-9]+  {printf("number %s\n",yytext);}

[a-zA-Z]+   {printf("Word %s\n",yytext);}

.|\n {ECHO ;}
%%

int main(){
    printf("Enter the statement: \n");
    yylex();
}

int yywrap(){
    return 1;
}