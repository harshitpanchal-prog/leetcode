class Solution {
public:
    char solveoperator(vector<char>vec,char op){
        if(op == '!'){
            return (vec[0] == 't')?'f' : 't';
        }
        if(op=='&'){
            for(char &ch : vec){
                if(ch=='f'){
                    return 'f';
                }
            }
            return 't';
        }
        if(op == '|'){
            return any_of(begin(vec),end(vec),[](char ch){return ch=='t';})?'t':'f';
        }
        return 't';

    }
    bool parseBoolExpr(string expression) {
        stack<char>st;
        int n=expression.length();
        for(int i=0 ; i<n ; i++){
            if(expression[i]==','){
                continue;
            }
            if(expression[i] != ')'){
                st.push(expression[i]);
            }else{
                vector<char>vec;
                while(st.top()!='('){
                    vec.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                st.push(solveoperator(vec,op));

            }
        }
        return st.top()=='t'?true:false;
    }
};