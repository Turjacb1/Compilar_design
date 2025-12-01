/* Q7: NFA a(b|c)* */
// a,abcbc valid 




#include <stdio.h>
#include <string.h>

int main(void) 
{
    char s[10001];

    scanf("%s", s);
    
    int current = 0;               // bit 0: q0, bit 1: q1
    current = 1; 
                      // start in q0
    for (int i=0; s[i]; i++) 
    {
        int next = 0;
        if (current & 1) 
        
        {         // from q0
            if (s[i]=='a') next |= 2;
        }

        if (current & 2) 
        {         // from q1
            if (s[i]=='b' || s[i]=='c') next |= 2;
        }
        
        current = next;
    }
    puts( (current & 2) ? "Accepted" : "Rejected");
    return 0;
}