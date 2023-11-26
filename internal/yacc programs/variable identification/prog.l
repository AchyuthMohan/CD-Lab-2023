%{
    #include "y.tab.h"
%}
%%
[a-zA-Z] {return LET;}
[0-9] {return DIG;}
\n {return 0;}
. {return *yytext;}
%%

int yywrap(){
    return 1;
}