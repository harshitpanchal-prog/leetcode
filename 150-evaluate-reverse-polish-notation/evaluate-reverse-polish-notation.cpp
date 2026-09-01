class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string,function<int(int,int)>>mp={
            {"+",[](int a,int b){return a+b;}},
            {"-",[](int a,int b){return a-b;}},
            {"*",[](int a,int b){return (long long)a * (long long)b;}},
            {"/",[](int a,int b){return a/b;}},
        };
        for(string& token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                int result = mp[token](b,a);
                st.push(result);
            }else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};