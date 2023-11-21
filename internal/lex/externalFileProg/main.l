
%{
#include<math.h>
FILE *fp;    
%}

header "#include<"[a-z]*".h>"
builtin [\t]*"printf(".*)"|[\t]*"scanf(".*)"|[\t]*"clrscr()"
mainfunction "int main()"
%%
{header} {printf("\nHEADER: %s",yytext);}
{builtin} {printf("\n built in: %s",yytext);}
%%
int main(){
    fp=fopen("input.txt","r");
    while(fp!=NULL){
        yyin=fp;
        yylex();
    }
}