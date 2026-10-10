class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        string token;
        stringstream ss(s);
        int countword=0;
        while(getline(ss,token,' ')){
            words.push_back(token);
            countword++;
        }
        int n=pattern.length();
        if(n!=countword){
            return false;
        }
        unordered_map<string,char>mp;
        set<char>st;
        for(int i=0 ; i<n ; i++){
            string word=words[i];
            char ch=pattern[i];
            if(mp.find(word)==mp.end() && st.find(ch)==st.end()){
                mp[word]=ch;
                st.insert(ch);
            }else if(mp[word]!=pattern[i]){
                return false;
            }
        }
        return true;

    }
};