class Solution {
public:
    bool isValid(string s) {
        stack<char> parenthesesStack;

        // Iterate over string
        for (char c: s){
            // Closing parentheses
            if (
                !parenthesesStack.empty() && (
                    c == ')' && parenthesesStack.top() == '(' ||
                    c == ']' && parenthesesStack.top() == '[' ||
                    c == '}' && parenthesesStack.top() == '{'
                )
            ){
                parenthesesStack.pop();
            }
            // Everything else
            else{
                parenthesesStack.push(c);
            }
        }
        // Check if stack is empty
        return parenthesesStack.empty();
    }
};
