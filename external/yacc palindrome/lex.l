%{
#include "y.tab.h"    
extern char yytext[];
%}

%%
[a-zA-Z]+ {return LETTER;}
%%
int yywrap(){
    return 1;
}