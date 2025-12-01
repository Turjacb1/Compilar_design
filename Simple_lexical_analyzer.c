/* Q8: simple lexer splitting a single line into IDENTIFIER, NUMBER, SYMBOL */
//input count = 123 + _temp;
/*(output -IDENTIFIER   "count"
SYMBOL       "="
NUMBER       "123"
SYMBOL       "+"
IDENTIFIER   "_temp"
SYMBOL       ";"*/




#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(){
    char line[1000];
    if(!fgets(line, sizeof line, stdin)) return 0;
    int i=0, n=strlen(line);
    while(i<n && line[i]!='\n'){
        if(isspace((unsigned char)line[i]))
        { i++; continue; }
        if(isalpha((unsigned char)line[i]) || line[i]=='_')
        {
            char lex[256]; int j=0;
            lex[j++]=line[i++];

            while(i<n && (isalnum((unsigned char)line[i]) || line[i]=='_')) lex[j++]=line[i++];
            lex[j]=0;

            printf("IDENTIFIER\t%s\n", lex);
            
        } else if(isdigit((unsigned char)line[i])){
            char lex[256]; int j=0;
            while(i<n && isdigit((unsigned char)line[i])) lex[j++]=line[i++];
            lex[j]=0;
            printf("NUMBER\t\t%s\n", lex);
        } else {
            char sym[2] = { line[i], 0 };
            printf("SYMBOL\t\t%s\n", sym);
            i++;
        }
    }
    return 0;
}
