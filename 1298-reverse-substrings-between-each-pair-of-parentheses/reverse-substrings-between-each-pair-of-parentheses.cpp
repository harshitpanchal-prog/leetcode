class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> open_bracket_idx;
        vector<int> door(n);
        for(int i=0 ; i<n ; i++){
            if(s[i]=='('){
                open_bracket_idx.push(i);
            }else if(s[i]==')'){
                int j = open_bracket_idx.top();
                open_bracket_idx.pop();
                door[i]=j;
                door[j]=i;
            }
        }

        string result;
        int flag=1;
        for(int i=0 ; i<n ; i+=flag){
            if(s[i]=='(' || s[i]==')'){
                i=door[i];
                flag=-flag;
            }else{
                result.push_back(s[i]);
            }
        }
        return result;
    }
};