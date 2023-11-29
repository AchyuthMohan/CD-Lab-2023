%{
    #include<stdio.h>
    #include<stdlib.h>
    int i=0,j,flag=0;
    extern char *yytext;
%}

%token LET

%%
input : LET {
    j=strlen(yytext);
    while(i<j){
        if(yytext[i]!=yytext[j]){
            flag=1;
            break;
        }
        i++;
        j--;
    }
    if(flag==1){
        printf("not palindrome\n");
    }
    else{
        printf("palindrome\n");
    }
};
%%
int main(){
    printf("enter the text: \n");
    yyparse();
    return 0;
}
int yyerror(){
    printf("error\n");
    exit(0);
}