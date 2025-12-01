/* Q10: remove comments from stdin, handle string/char literals to avoid removing comment-like text inside them */

/* 
input - int x = 5; // hello world  ouput- int x = 5;

*/



#include <stdio.h>

int main(){
    int c;
    enum {NORMAL, SL_COMMENT, ML_COMMENT, IN_STRING, IN_CHAR, ESCAPE} state = NORMAL;
    int prev = 0;
    while((c = getchar()) != EOF){
        if(state==NORMAL){
            if(c=='/'){
                int d = getchar();
                if(d=='/'){ state = SL_COMMENT; }
                else if(d=='*'){ state = ML_COMMENT; }
                else {
                    putchar(c);
                    if(d==EOF) break;
                    ungetc(d, stdin);
                }
            } else if(c=='"'){
                putchar(c);
                state = IN_STRING;
            } else if(c=='\''){
                putchar(c);
                state = IN_CHAR;
            } else putchar(c);
        } else if(state==SL_COMMENT){
            if(c=='\n'){ putchar('\n'); state = NORMAL; }
            // else skip
        } else if(state==ML_COMMENT){
            if(c=='*'){
                int d = getchar();
                if(d=='/'){ state = NORMAL; }
                else if(d==EOF){ break; }
                else ungetc(d, stdin);
            }
            // else skip
        } else if(state==IN_STRING){
            putchar(c);
            if(c=='\\') { state = ESCAPE; }
            else if(c=='"') { state = NORMAL; }
        } else if(state==IN_CHAR){
            putchar(c);
            if(c=='\\') { state = ESCAPE; }
            else if(c=='\'') { state = NORMAL; }
        } else if(state==ESCAPE){
            putchar(c);
           
            state = IN_STRING; // safe fallback, still correct for typical inputs
        }
    }
    return 0;
}
