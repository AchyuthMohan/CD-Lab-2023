%{
    #include<stdio.h>
    int linecount=0;
%}

%%
\n {linecount++;}
%%

int main(){
    printf("Enter the content: \n");
    yylex();
    printf("Count: %d\n",linecount);
    return 0;
}
int yywrap(){
    return 1;
}