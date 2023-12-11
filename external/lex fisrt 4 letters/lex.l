%{
    #include<stdio.h>
    #include<stdlib.h>
    FILE *fp;
%}

%%
[a-zA-Z]*"achy"[a-zA-Z]* { }
[a-zA-Z]* {printf("%s",yytext);}
%%

int main(){
    fp=fopen("input.txt","r");
    yyin=fp;
    yylex();
}
int yywrap(){
    return 1;
}