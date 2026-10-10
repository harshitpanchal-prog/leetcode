class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        string token;
        stringstream ss(s);
        int counttoken=0;
        unordered_map<char,int>chartoidx;
        unordered_map<string,int>wordtoidx;
        int i=0;
        int n=pattern.size();
        while(ss>>token){
            counttoken++;
            if(i==n || chartoidx[pattern[i]]!=wordtoidx[token]){
                return false;
            }
            chartoidx[pattern[i]]=i+1;
            wordtoidx[token]=i+1;
            i++;    
        }
        if(counttoken != n || i!=n){
            return false;
        }
        return true;
    }
};