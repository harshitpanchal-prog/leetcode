class Solution {
public:
    string remove_substr(string &s, string &matchstr){
        stack<char>st;
        for(char &ch : s){
            if(ch==matchstr[1] && !st.empty() && st.top()==matchstr[0]){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        string temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(begin(temp),end(temp));
        return temp;
    }

    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int score = 0;
        string maxstr = (x>=y)?"ab" : "ba";
        string minstr = (x<y)?"ab" : "ba";

        string temp_first=remove_substr(s,maxstr);
        int L = temp_first.length();
        int char_removed = (n-L);
        score+=(char_removed/2)*max(x,y);

        string temp_second=remove_substr(temp_first,minstr);
        char_removed= L - temp_second.length();
        score+=(char_removed/2)*min(x,y);
        return score;
    }
};