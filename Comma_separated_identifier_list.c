/* Q1: check comma-separated list of identifiers */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char *s;
int pos;

int isIdStart(char c)
{ return isalpha((unsigned char)c) || c=='_'; }
int isIdChar(char c)
{ return isalnum((unsigned char)c) || c=='_'; }

int id(){
    if(!isIdStart(s[pos])) return 0;
    pos++;
    while(isIdChar(s[pos])) pos++;
    return 1;
}

int L(){
    if(!id()) return 0;
    if(s[pos]==','){
        pos++;
        return L();
    }
    return 1;
}

int main(){
    char line[1000];
    if(!fgets(line, sizeof line, stdin)) return 0;
    // trim newline
    line[strcspn(line, "\n")] = 0;
    s = line; pos = 0;
    // skip leading spaces
    while(isspace((unsigned char)s[pos])) pos++;
    int ok = L();
    while(isspace((unsigned char)s[pos])) pos++;
    if(ok && s[pos]=='\0') printf("Valid\n"); else printf("Invalid\n");
    return 0;
}
