%{
#include "y.tab.h"
%}

%%
(html|p|head|body) {return TAG;}
[<] {return OPEN;}
[>] {return CLOSE;}
[/] {return SLASH;}
[a-zA-Z]* {return LETTER;}
[ ] {return LETTER;}
[\n\t] {return 0;}
%%
int yywrap(){
return 1;
}


