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
    printf("\nResult=%d\n", $$);
    return 0;
};
E: E '+' E {$$ = $1 +$2;}
 | E '-' E {$$=$1 - $2; }
 | E '*' E {$$=$1*$2 ;}
 | E '/' E {$$=$1/$2;}
 | E '%' E {$$=$1 % $2;}
 | '('E')' {$$=$2 ;}
 | NUMBER {$$ =$1;}
 ;

 %%
 int main()
{
    printf("Enter the expression: \n");
    yyparse();
    return 0;
}
int yyerror(){
    printf("Error occured\n");
    exit(0);
}
