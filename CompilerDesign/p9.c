%option noyywrap;
%{
    #include<stdio.h>    
    FILE * out;
%}

%%
"<"[^>]*">" {fprintf(out,"%s\n",yytext);}
. ;
%%


int main(){
    FILE *in = fopen("input.text","r");
    out = fopen("output.txt" , 'w');
    if(!in | !out){
        return 1;
    }
    yyin = in;
    yylex();
    
    fclose(in);
    fclose(out);


}