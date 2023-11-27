%{
    #include<stdio.h>
%}

%%
[A-Z][A-Z]+ {printf("%s\n",yytext);}
[a-z]+  {}
[0-9]+ {}
%%
int main(){
    printf("Enter the string: \n");
    yylex();
}
int yywrap(){
    return 1;
}