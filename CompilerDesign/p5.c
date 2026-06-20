%{
#include <stdio.h>
%}

/* Definitions */
DIGIT       [0-9]
LETTER      [a-zA-Z_]
ID          {LETTER}({LETTER}|{DIGIT})*
KEYWORD     "int"|"float"|"char"|"double"|"if"|"else"|"while"|"for"|"return"|"void"|"switch"|"case"|"break"
OPERATOR    "+"|"-"|"*"|"/"|"="|"=="|"!="|"<"|">"|"<="|">="|"&&"|"||"|"++"|"--"
SEPARATOR   "("|")"|"{"|"}"|"["|"]"|";"|","|"."

%%

{KEYWORD}    { printf("KEYWORD:    %s\n", yytext); }
{ID}         { printf("IDENTIFIER: %s\n", yytext); }
{OPERATOR}   { printf("OPERATOR:   %s\n", yytext); }
{SEPARATOR}  { printf("SEPARATOR:  %s\n", yytext); }

[0-9]+(\.[0-9]+)? { printf("NUMBER:     %s\n", yytext); }

[ \t\n]+     { /* Ignore whitespace */ }
.            { printf("UNKNOWN:    %s\n", yytext); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter code snippet (Ctrl+D to exit):\n");
    yylex();
    return 0;
}