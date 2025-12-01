/* Q6: Even number of 1s */
#include <stdio.h>
//input - 11 valid  1011-invalid
int main(void) {
    char s[10001];
    scanf("%s", s);
    int state = 0;                 // 0 = even, 1 = odd
    for (int i=0; s[i]; i++) {
        if (s[i]=='1') state = 1-state;
    }
    puts(state==0 ? "Accepted" : "Rejected");
    return 0;
}