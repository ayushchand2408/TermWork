%option noyywrap;
%{
    #include<stdio.h>    
    File * out;
%}

%%
[\t]+ {fprintf(out, " ")};
[\n]+ {fprintf(out,"\n");}
. {fprintf(out,"%s" , yytext)};
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