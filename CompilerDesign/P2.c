%{
#include<stdio.h>
int lines=0, spaces=0, tabs=0, rest=0;
%}

%%
\n      { lines++; }      /* Match newline */
" "     { spaces++; }     /* Match space */
\t      { tabs++; }       /* Match tab */
.       { rest++; }       /* Match any other character */
%%

int main() {
    printf("Enter the input (Press Ctrl+D to stop):\n");
    yylex();
    
    printf("\n--- Results ---\n");
    printf("Lines: %d\n", lines);
    printf("Spaces: %d\n", spaces);
    printf("Tabs: %d\n", tabs);
    printf("Other Characters: %d\n", rest);
    
    return 0;
}

int yywrap() {
    return 1;
}