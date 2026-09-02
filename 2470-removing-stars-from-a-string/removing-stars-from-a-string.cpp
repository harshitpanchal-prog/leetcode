class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        vector<char> temp(n);
        int j=0;
        for(int i=0 ; i<n ; i++){
            if(s[i] == '*'){
                j--;
            }else{
                temp[j]=s[i];
                j++;
            }
        }
        string result="";
        for(int k=0 ; k <= j-1 ; k++){
            result.push_back(temp[k]);
        }
        return result;
    }
};