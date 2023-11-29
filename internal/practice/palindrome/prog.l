%{
#include "y.tab.h"
%}

%%
[a-zA-Z]* {return CHAR;}
%%

int yywrap(){
return 1;
}

