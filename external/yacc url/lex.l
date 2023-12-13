%{
#include "y.tab.h"    
%}

%%
http {return HTTPS;}
https {return HTTPS;}
[:] {return FC;}
[/] {return SLASH;}
[a-z]+"."[a-z]+ {return HOST;}
[a-z]+ {return PATH;}
[=] {return EQ;}
%%

int yywrap(){
    return 1;
}