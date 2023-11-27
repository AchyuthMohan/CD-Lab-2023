%{
#include<stdio.h>    
int vcount=0;
int ccount=0;
%}
%%
[ \t\n] ;
[aeiouAEIOU] {vcount++;}
[^aeiouAEIOU] {ccount++;}
%%

int main(){
    printf("Enter the string: \n");
    yylex();
    printf("VCount: %d\n",vcount);
    printf("CCount: %d\n",ccount);
}
int yywrap(){
    return 1;
}


//type CTR + D to get output