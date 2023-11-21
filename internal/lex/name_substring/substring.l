%{
#include <stdio.h>
#include <string.h>
FILE *fp;
%}

substring [a-z]*"achy"[a-z]*
%%
{substring} {printf("%s",yytext);}
%%


int main() {
    fp=fopen("input.txt","r");
    while(fp!=NULL){
        yyin=fp;
        yylex();
    }
}
