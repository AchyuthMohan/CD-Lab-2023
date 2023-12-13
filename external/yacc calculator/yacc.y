%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%
ArithmeticExpression: E {
    printf("Result: %d\n",$$);
    return 0;
};
E: E'+'E{$$=$1+$3;}
|E'-'E{$$=$1-$3;}
|E'*'E{$$=$1*$3;}
|E'/'E{$$=$1/$3;}
|E'%'E{$$=$1%$3;}
|'('E')'{$$=$2;}
|NUMBER {$$=$1;}
%%

int main(){
    printf("Enter the expression: ");
    yyparse();
    return 0;
}
int yyerror(){
    printf("Invalid Expression\n");
    return 1;
}