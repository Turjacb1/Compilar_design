/* Q10: remove comments from stdin, handle string/char literals to avoid removing comment-like text inside them */

/* 
input - int x = 5; // hello world  ouput- int x = 5;

*/



#include <iostream>
using namespace std;

int main() {
    string s;

    while (getline(cin, s)) 
    
    {
        for (int i = 0; i < s.size(); 
        
        i++
    ) 
        
        {

            // single-line comment //
            if (s[i]=='/' && s[i+1]=='/') 
            break;

            // multi-line comment /* ... */
            if (s[i]=='/' && s[i+1]=='*') 
            {
                i += 2;
                while (!(s[i]=='*' && s[i+1]=='/')) i++;
                i++; // skip '/'
            }
            else {
                cout << s[i];
            }
        }
        cout << "\n";
    }
}