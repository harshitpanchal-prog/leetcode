class Solution {
public:
    int minSwaps(string s) {
        stack<int> st;
        for(char &ch:s){
            if(ch == '['){
                st.push(ch);
            }else if(!st.empty()){
                st.pop();
            }
        }
        float a=st.size();
        return ceil(a/2.0);
    }
};