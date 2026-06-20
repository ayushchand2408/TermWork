%{
#include <stdio.h>
%}

/* Rule Section */
%%
[a-zA-Z_][a-zA-Z0-9_]* { printf("Valid Identifier: %s\n", yytext); }
[0-9][a-zA-Z0-9_]* { printf("Invalid Identifier (Starts with digit): %s\n", yytext); }
.|\n                      { /* Ignore other characters */ }
%%

int main() {
    printf("Enter input to find valid C identifiers:\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}