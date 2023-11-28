%{
    #include<stdio.h>
    #include<stdlib.h>

%}
%token LET

%%
start: LET {if(isPalindrome($1)) printf("palindrome"); else printf("not palindrome");};
%%

int isPalindrome(char *temp){
    int i=0;
    int j=strlen(temp)-1;
    while(i<j){
        if(temp[i]!=temp[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main(){
    printf("Enter teh expresion:\n");
    yyparse();
    return 0;
}
int yyerror(){
    printf("No\n");
    exit(0);
}
