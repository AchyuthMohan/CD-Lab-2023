%{
    #include<stdio.h>
%}

%%
a[a-zA-Z]* {printf("%s starts with a \n",yytext);}

%%
int main(){
    printf("Enter the statement:\n");
    yylex();
}
int yywrap(){
    return 1;
}