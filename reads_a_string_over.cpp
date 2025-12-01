/* Q4: check strings of the form a^n b^n using S -> a S b | a b */
//intput -aaabbb-valid  aabbb-invalid


#include <iostream>
#include <string>

std::string input;
int pos = 0;

bool S() {
    if (pos >= input.length()) 
    
    return false;

    if (input[pos] == 'a') 
    {
        pos++; 

       
        if (pos < input.length() && input[pos] == 'b') 
        {
            pos++; 
            return true;
        }
        
        else if (S()) 
        {
            if (pos < input.length() && input[pos] == 'b') {
                pos++;
                return true;
            }
        }
    }

    return false;
}

int main()

{
    std::cout << "Enter a string over {a, b}: ";
    std::cin >> input;

    pos = 0;
    if (S() && pos == input.length()) 
    {
        std::cout << "String is valid (belongs to a^n b^n).\n";
    }
     else 
    {
        std::cout << "String is invalid.\n";
    }

    return 0;
}
