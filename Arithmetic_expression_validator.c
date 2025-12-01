/* Q2: recursive-descent parser for expressions:
   E -> T E'
   E' -> + T E' | - T E' | ε
   T -> F T'
   T' -> * F T' | / F T' | ε
   F -> ( E ) | id | number
*/
/*


input-a + b * (c - 3)
  output -valid
  input -a + * c
ouput-invalid 

*/



#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef enum {TOK_ID, TOK_NUM, TOK_PLUS, TOK_MINUS, TOK_MUL, TOK_DIV, TOK_LP, TOK_RP, TOK_END, TOK_ERR} Token;

char buf[1000];
int idx=0;
Token look;
char lexeme[256];

void nextToken(){
    while(isspace((unsigned char)buf[idx])) idx++;
    int i=0;
    char c = buf[idx];
    if(c=='\0'){ look = TOK_END; return;}
    if(isalpha((unsigned char)c) || c=='_'){
        while(isalnum((unsigned char)buf[idx]) || buf[idx]=='_') lexeme[i++]=buf[idx++];
        lexeme[i]=0; look = TOK_ID; return;
    }


    if(isdigit((unsigned char)c)){
        while(isdigit((unsigned char)buf[idx])) lexeme[i++]=buf[idx++];
        lexeme[i]=0; look = TOK_NUM; return;
    }
    idx++;


    switch(c){
        case '+': look = TOK_PLUS; break;
        case '-': look = TOK_MINUS; break;
        case '*': look = TOK_MUL; break;
        case '/': look = TOK_DIV; break;
        case '(': look = TOK_LP; break;
        case ')': look = TOK_RP; break;
        default: look = TOK_ERR; break;
    }
}



int E(); int Eprime(); int T(); int Tprime(); int F();

int E(){ return T() && Eprime(); }
int Eprime(){
    if(look==TOK_PLUS || look==TOK_MINUS){
        nextToken();
        if(!T()) return 0;
        return Eprime();
    }
    return 1; // epsilon
}


int T(){ return F() && Tprime(); }
int Tprime(){
    if(look==TOK_MUL || look==TOK_DIV){
        nextToken();
        if(!F()) return 0;
        return Tprime();
    }
    return 1;
}


int F(){
    if(look==TOK_LP){
        nextToken();
        if(!E()) return 0;
        if(look!=TOK_RP) return 0;
        nextToken();
        return 1;
    } else if(look==TOK_ID || look==TOK_NUM){
        nextToken();
        return 1;
    }
    return 0;
}



int main(){
    if(!fgets(buf, sizeof buf, stdin)) return 0;
    buf[strcspn(buf, "\n")] = 0;
    idx = 0; nextToken();
    int ok = E() && look==TOK_END;
    printf(ok? "Valid\n":"Invalid\n");
    return 0;
}
