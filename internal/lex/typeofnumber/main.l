%{
#include<math.h>
FILE *fp;    
%}
binary [0-1]+
octal [0-7]+
hex [0-9A-F]+
decimal [0-9]+

%%
{binary} {printf("The number %s is binary\n", yytext);}
{octal} {printf("The number %s is octal\n", yytext);}
{hex} {printf("The number %s is hex\n", yytext);}
%%

int main(){
    fp=fopen("input.txt","r");
    while(fp!=NULL){
        yyin=fp;
        yylex();
    }
}