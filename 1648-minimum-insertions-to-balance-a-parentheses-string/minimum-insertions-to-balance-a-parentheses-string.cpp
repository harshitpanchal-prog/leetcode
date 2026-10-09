
class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int insertions = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } 
            else {
                // If the next character is ')',
                // use it as the second closing parenthesis.
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } 
                else {
                    // Insert the missing second ')'.
                    insertions++;
                }

                if (open > 0) {
                    open--;
                } 
                else {
                    // Insert a missing '('.
                    insertions++;
                }
            }
        }

        // Every remaining '(' requires two ')'.
        insertions += open * 2;

        return insertions;
    }
};