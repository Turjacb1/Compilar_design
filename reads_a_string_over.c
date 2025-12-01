/* Q4: check strings of the form a^n b^n using S -> a S b | a b */
//intput -aaabbb-valid  aabbb-invalid

#include <stdio.h>
#include <string.h>

const char *s;
int pos;

int S(){
    if(s[pos]=='a'){
        pos++; // consume 'a'
        if(S()){
            if(s[pos]=='b'){
                pos++;
                return 1;
            } else return 0;
        } else return 0;
    }
    // epsilon — but grammar requires at least 'ab' so epsilon only allowed in recursive step.
    return 1;
}

int main(){
    char line[1000];
    if(!fgets(line, sizeof line, stdin)) return 0;
    line[strcspn(line,"\n")] = 0;
    s = line; pos = 0;
    // To ensure at least one 'a' 'b', we'll require final acceptance and not empty string.
    if(s[0]=='\0'){ printf("Invalid\n"); return 0; }
    int ok = S() && s[pos]=='\0';
    printf(ok? "Valid\n":"Invalid\n");
    return 0;
}
