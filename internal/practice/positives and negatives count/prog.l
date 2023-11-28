%{
    #include<stdio.h>
    #include<stdlib.h>
    int p=0,n=0;
%}

%%
-[0-9]+ {n++;}
[0-9]+ {p++;}
%%

int main(){
    printf("Enter the value\n");
    yylex();
    printf("negatives: %d\n",n);
    printf("positives: %d\n",p);
}