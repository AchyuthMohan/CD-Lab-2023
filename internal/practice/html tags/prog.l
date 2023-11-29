%{
    #include "y.tab.h"
%}

%%
[<] {return OPEN;}
[/] {return SLASH;}
[>] {return CLOSE;}
(html|p|head|body) {return TAG;}
[a-zA-Z]* {return LETTER; }
[ ] {return LETTER;}
[\n\t] {return 0;}
%%

int yywrap(){
    return 1;
}