%{
    #include<stdio.h>
    #include<stdlib.h>
    int vowels=0,conso=0;
%}

%%
[aeiouAEIOU] {vowels++;}
[^aeiouAEIOU] {conso++;}

%%
int main(){
    printf("Enter the string\n");
    yylex();
    printf("Vowels: %d\n",vowels);
    printf("Consonants:%d ",conso);
}
