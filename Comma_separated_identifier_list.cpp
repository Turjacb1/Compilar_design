/* Q1: check comma-separated list of identifiers */
//nput: a,b,c → Valid

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string s;
int pos = 0;


bool isID() {
    if (pos >= s.length()) 
    return false;

    // first character must be letter or _
    if (!isalpha(s[pos]) && s[pos] != '_') 
    return false;

    pos++;

    // the rest can be letters, digits or _
    while (pos < s.length() && (isalnum(s[pos]) || s[pos] == '_'))
        pos++;

    return true;
}


bool L() {
    if (!isID()) 
    return false;  // must start with an id

    // while there is a comma, consume it and parse next id
    while (pos < s.length() && s[pos] == ',') {
        pos++;             // consume comma
        if (!isID()) return false;  // must have another id after comma
    }

    return true;
}

int main()
 {
    cout << "Enter comma-separated list: ";
    getline(cin, s);

    pos = 0;

    if (L() && pos == s.length())
        cout << "Valid\n";
    else
        cout << "Invalid\n";

    return 0;
}
