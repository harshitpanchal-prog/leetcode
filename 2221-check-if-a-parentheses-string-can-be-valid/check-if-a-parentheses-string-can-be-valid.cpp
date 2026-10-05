class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();
        if(n%2 !=0){
            return false;
        }
        stack<int>open_close;
        stack<int>open_bracket;

        for(int i=0 ; i<n ; i++){
            if(locked[i]=='0'){
                open_close.push(i);
            }else if(s[i]=='('){
                open_bracket.push(i);
            }else if(s[i]==')'){
                if(!open_bracket.empty()){
                    open_bracket.pop();
                }else if(!open_close.empty()){
                    open_close.pop();
                }else{
                    return false;
                }
            }
        }
        while(!open_bracket.empty() && !open_close.empty() && open_bracket.top()<open_close.top()){
            open_bracket.pop();
            open_close.pop();
        }
        return open_bracket.empty();
    }
};