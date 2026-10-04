#include <string>
#include <stack>

using namespace std;

class Solution { 
public: 
    bool checkValidString(string s) { 
        // Use stack<int> to store the indices of the characters
        stack<int> extraopen_bracket; 
        stack<int> astrick; 

        for (int i = 0; i < s.size(); i++) { 
            char ch = s[i]; // Declare and initialize ch
            
            if (ch == '(') { 
                extraopen_bracket.push(i); 
            } else if (ch == '*') { 
                astrick.push(i); 
            } else { // ch == ')'
                if (!extraopen_bracket.empty()) { 
                    extraopen_bracket.pop(); 
                } else if (!astrick.empty()) { 
                    astrick.pop(); 
                } else { 
                    return false; 
                } 
            }
        } 

        // Match remaining open brackets with remaining asterisks
        while (!extraopen_bracket.empty()) { 
            if (astrick.empty()) { 
                return false; 
            } 
            
            // In C++, top() retrieves the value, pop() deletes it
            int openindex = extraopen_bracket.top(); extraopen_bracket.pop(); 
            int closeindex = astrick.top(); astrick.pop(); 
            
            // An open bracket '(' cannot be closed by a '*' that appeared before it
            if (openindex > closeindex) { 
                return false; 
            } 
        } 

        return extraopen_bracket.empty(); 
    } 
};
