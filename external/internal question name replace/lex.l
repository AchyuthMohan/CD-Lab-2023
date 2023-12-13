%{
#include<stdio.h>
#include<stdlib.h>
FILE *fp;
FILE *fo;    
int count=0;
%}

%%
[a-zA-Z]*"hello"[a-zA-Z]* {count++;
if(count%2==1){
    fprintf(fo,"%d ",03);
}
else{
    fprintf(fo,"%s",yytext);
}
}
[a-zA-Z]* {fprintf(fo,"%s",yytext); } 
[\n\t ] { fprintf(fo,"%s",yytext);}
%%

int main(){
    fp=fopen("input.dat","r");
    fo=fopen("output.dat","w");
    yyin=fp;
    yylex();
    printf("Count: %d\n",count);
    return 0;
}

int yywrap(){
    return 1;
}