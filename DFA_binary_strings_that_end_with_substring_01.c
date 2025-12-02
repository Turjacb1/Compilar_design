/* Q5: Binary strings ending with 01 */
//intput -1001 valid  100-invalid 



#include <stdio.h>
#include <string.h>

int main(void) 
{
    char s[10001];
    scanf("%s", s);

    int n = strlen(s);

    if (n < 2) 
    { 
        puts("Rejected"); 
        return 0; 
    }
    puts( s[n-2]=='0' && s[n-1]=='1' ? "Accepted" : "Rejected");
    return 0;
}