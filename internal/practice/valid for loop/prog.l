%{
    #include "y.tab.h"
%}

%%
for {return FOR;}
[=] {return EQ;}
[(] {return LPAREN; }
int  {return DATATYPE; }
float {return DATATYPE; }
char {return DATATYPE; }
double {return DATATYPE; }
[a-zA-Z][a-zA-Z]* {return ID;}
[+][+] {return OP;}
[-][-] {return OP;}
[0-9]+ {return NUMBER; }
[;] {return SC; }
[<>]  {return COMP; }
[<>][=] {return COMP;}
[)] {return RPAREN; }
[ ] {}
[\n \t] {return 0;}
%%

int yywrap(){
    return 1;
}