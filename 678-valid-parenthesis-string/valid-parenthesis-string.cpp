class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // '*' acts as ')'
                high++;  // '*' acts as '('
            }

            // Even the maximum possible '(' count became negative
            if (high < 0)
                return false;

            // We cannot have fewer than 0 unmatched '('
            low = max(low, 0);
        }

        // If minimum possible unmatched '(' is 0,
        // we can make the string valid.
        return low == 0;
    }
};