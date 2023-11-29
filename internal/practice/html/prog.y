%{
#include<stdio.h>
#include<stdlib.h>

%}
%token TAG SLASH OPEN CLOSE LETTER

%%
stmt: OPEN TAG CLOSE CONTENT  OPEN SLASH TAG CLOSE
CONTENT: LETTER | stmt stmt | stmt LETTER

%%

int main(){
	printf("Enter the statemnet: \n");
	yyparse();
	printf("matched\n");
	return 0;
}

int yyerror(){
printf("No match\n");
exit(0);
}
