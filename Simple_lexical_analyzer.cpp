/* Q8: simple lexer splitting a single line into IDENTIFIER, NUMBER, SYMBOL */
//input count = 123 + _temp;
/*(output -IDENTIFIER   "count"
SYMBOL       "="
NUMBER       "123"
SYMBOL       "+"
IDENTIFIER   "_temp"
SYMBOL       ";"*/




#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int i = 0;
    while (i < s.size()) 
    {

        if (isspace(s[i])) { i++; continue; 
        
        }

        if (isalpha(s[i]) || s[i]=='_') 
        {
            string tok;
            while (isalnum(s[i]) || s[i]=='_') tok += s[i++];
            cout << "IDENTIFIER: " << tok << "\n";
        }
        else if (isdigit(s[i])) 
        
        {
            string tok;
            while (isdigit(s[i])) tok += s[i++];
            cout << "NUMBER: " << tok << "\n";
        }
        else 
        {
            cout << "SYMBOL: " << s[i++] << "\n";
        }
    }
}