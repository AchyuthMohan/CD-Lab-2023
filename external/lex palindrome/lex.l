%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%%
[a-zA-Z]+ {
    int i=0;
    int j=strlen(yytext)-1;
    while(i<j){
        if(yytext[i]!=yytext[j]){
            printf("Not Palindrome\n");
            return 0;
        }
        i++;
        j--;
    }
    printf("Palindrome\n");
    return 0;
}

%%

int main(){
    printf("Enter the text: ");
    yylex();
    return 0;
}
int yywrap(){
    return 1;
}