/* Q3: balanced-parentheses according to S -> ( S ) S */
//intput --- (()())   ouput-valid 


#include <stdio.h>
#include <string.h>

const char *s;
int pos;

int S(){
    if(s[pos]=='('){
        pos++; // consume '('
        if(!S()) return 0;
        if(s[pos]!=')') return 0;
        pos++; // consume ')'
        if(!S()) return 0;
        return 1;
    }
    // epsilon
    return 1;
}

int main(){
    char line[1000];
    if(!fgets(line, sizeof line, stdin)) return 0;
    line[strcspn(line,"\n")] = 0;
    s = line; pos = 0;
    int ok = S() && s[pos]=='\0';
    printf(ok? "Valid\n":"Invalid\n");
    return 0;
}
