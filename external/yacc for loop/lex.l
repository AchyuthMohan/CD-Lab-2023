%{
    #include "y.tab.h"
%}

  
%%
[(] {return OPEN;}
[)] {return CLOSE;}
for {return FOR;}
[a-zA-Z]* {return LET;}
[=] {return EQ;}
[0-9]+ {return DIG;}
[<] {return  LT;}
[;] {return SC;}
[+] {return OP;}
[{] {return OPENCURL;}
[}] {return CLOSECURLY;}
[\n\t ] { }
%%

int yywrap(){
    return 1;
}