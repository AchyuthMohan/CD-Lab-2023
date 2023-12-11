%{
    #include<stdio.h>
    int spaces=0;
    FILE *fp;
%}

%%
[\n\t ] {spaces++;}
%%

int main(){
    fp=fopen("input.txt","r");
    yyin=fp;
    yylex();
    printf("Count: %d",spaces);
}
int yywrap(){
    return 1;
}