class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>last_skip_length;
        string result;
        for(char &ch : s){
            if(ch=='('){
                last_skip_length.push(result.length());
            }else if(ch==')'){
                int l=last_skip_length.top();
                last_skip_length.pop();
                reverse(begin(result)+l , end(result));
            }else{
                result.push_back(ch);
            }
        }
        return result;
    }
};