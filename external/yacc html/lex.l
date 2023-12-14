%{
    #include "y.tab.h"
%}

%%
[<] {return OPEN;}
(html|body|h1|h2|p) {return TAG;}
[>] {return CLOSE;}
[/] {return SLASH;}
[a-zA-Z0-9]+ {return LETTER;}
[\n\t ] { }

. {return yytext[0];}
%%

int yywrap(){
    return 1;
}