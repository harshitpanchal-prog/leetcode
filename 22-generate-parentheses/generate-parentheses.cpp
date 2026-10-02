class Solution {
public:
    void backtrack(vector<string>&result,int open,int close,string curr,int n){
        if(open == n && close == n){
            result.push_back(curr);
            return;
        }
        if(open<n){
            backtrack(result,open+1,close,curr+'(',n);
        }
        if(close<open){
            backtrack(result,open,close+1,curr+')',n);
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        
        backtrack(result,0,0,"",n);
        return result;
    }
};