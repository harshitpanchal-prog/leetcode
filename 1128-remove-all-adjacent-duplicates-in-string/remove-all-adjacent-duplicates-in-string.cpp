class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(char& ch:s){
            if(st.empty() || st.top() != ch){
                st.push(ch);
            }else{
                st.pop();
            }
        }
        string result="";
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        reverse(begin(result),end(result));
        return result;
    }
};