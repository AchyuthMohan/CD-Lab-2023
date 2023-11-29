%{
#include<stdio.h>
#include<stdlib.h>
int i=0,j,flag=0;
extern char *yytext;
%}

%token CHAR;
%%
input: CHAR {
	while(i<j){
		if(yytext[i]!=yytext[j]){
			flag=1;
			break;	
		}
		i++;
		j--;
	}
if(flag==1){
	printf("Not palindrome");
	return 0;
}
else{
printf("Palindrome");
return 0;
}
};

%%

int main(){
	printf("Enter the text: \n");
	yyparse();
	return 0;
}
int yyerror(){
	printf("Error\n");
	exit(0);
}
