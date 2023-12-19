%{
#include "y.tab.h"    
%}

%%
do {return DO;}
while {return WHILE;}
[{] {return OPENCURLY;}
[a-zA-Z]+ {return LETTER;}
[+] {return OP;}
[;] {return SC;}
[}] {return CLOSECURLY;}
[(] {return OPENPAREN;}
[<] {return LT;}
[0-9]+ {return NUMBER;}
[)] {return CLOSEPAREN;}
[\n\t ] {return 0;}
. {return yytext[0];}
%%

int yywrap(){
    return 1;
}