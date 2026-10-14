class Solution {
public:
    unordered_set<string>st;
    void getset(){
        for(int i=0 ; i<=29 ; i++){
            string s=to_string(1<<i);
            sort(begin(s),end(s));
            st.insert(s);
        }
    }
    bool reorderedPowerOf2(int n) {
        if(st.empty()){
            getset();
        }
        string s=to_string(n);
        sort(begin(s),end(s));
        return st.count(s);
    }
};