/* Q9: C keyword / identifier classifier */

/*
input -int  output -Keyword
input -int123 output -Identifier
*/



#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char* keywords[] = {"int","if","else","for","while","return","char","float","double","void",NULL};

int is_keyword(const char* s) 
{
    for (int i=0; keywords[i]; 
        i++) 
    if (!strcmp(s,keywords[i]))
    return 1;
    return 0;
}

int valid_id(const char* s) 
{
    if (! (isalpha(*s) || *s=='_') ) 
    return 0;
    for (; *s; s++) if (! (isalnum(*s) || *s=='_') ) 
    return 0;
    return 1;
}

int main(void) 
{
    char word[256];
    while (scanf("%255s", word) == 1) 
    {
        if (is_keyword(word)) 
        puts("Keyword");

        else if (valid_id(word)) 
        puts("Identifier");

        else 
        puts("Invalid");
    }

    return 0;
}