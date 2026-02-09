%{
#include <stdio.h>
%}

%option noyywrap

DIGIT   [0-9]
LETTER  [a-zA-Z]
ID      {LETTER}({LETTER}|{DIGIT})*
NUMBER  {DIGIT}+

%%
"begin"     { printf("KEYWORD: begin\n"); }
"end"       { printf("KEYWORD: end\n"); }
"var"       { printf("KEYWORD: var\n"); }
"print"     { printf("KEYWORD: print\n"); }

{ID}        { printf("IDENTIFIER: %s\n", yytext); }
{NUMBER}    { printf("NUMBER: %s\n", yytext); }

"="         { printf("OPERATOR: =\n"); }
"+"         { printf("OPERATOR: +\n"); }
"-"         { printf("OPERATOR: -\n"); }

";"         { printf("DELIMITER: ;\n"); }

[ \t\n]+    { }

.           { printf("UNKNOWN: %s\n", yytext); }
%%

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
    }
    yylex();
    return 0;
}

