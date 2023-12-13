%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%%
[0-9]+ {
    int n=atoi(yytext);
    if(n%2==1){
        printf("The number is odd\n");
        if(n==2){
            printf("Prime\n");
            return 0;
        }
        if(n<=1){
            printf("Not Prime\n");
            return 0;
        }
        for(int i=2;i<=(n/2);i++){
            if(n%i==0){
                printf("Non Prime\n");
                return 0;
            }
        }
        printf("Prime number\n");
        return 0;
    }
    else{
        printf("Number is Even\n");
        return 0;
    }
}
%%

int main(){
    printf("Enter the number: \n");
    yylex();
    return 0;
}