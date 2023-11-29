%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%%
^[?][a-zA-Z]* {printf("%s\n",yytext);}
^[!][a-zA-Z]* {printf("%s\n",yytext);}
[a-zA-Z]* { }
%%
int main(){
    printf("Enter the text:\n");
    yylex();
    return 0;
}