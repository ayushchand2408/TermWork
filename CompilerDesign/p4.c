%{
#include <stdio.h>
%}

/* Definitions */
DIGIT    [0-9]
INTEGER  {DIGIT}+
/* A float must have a decimal point or an exponent */
FLOAT    {DIGIT}*"."{DIGIT}+|{DIGIT}+"."{DIGIT}*|({DIGIT}+|{FLOAT})[eE][+-]?{DIGIT}+

%%

{INTEGER}   { printf("Integer: %s\n", yytext); }
{FLOAT}     { printf("Float:   %s\n", yytext); }
[ \t\n]     { /* Ignore whitespace */ }
.           { printf("Unknown: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter input (Ctrl+D to exit):\n");
    yylex();
    return 0;
}