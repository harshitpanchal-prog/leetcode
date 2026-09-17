class Solution {
public:
    int maxDifference(string s) {
        
        vector<int> mp(26,0);
        for(char& ch : s){
            mp[ch-'a']++;
        }
        int maxodd=INT_MIN;
        int mineven=INT_MAX;
        for(int i=0 ; i<26 ; i++){
            if(mp[i]==0){
                continue;
            }
            if(mp[i]%2 == 0){
                mineven=min(mineven,mp[i]);
            }else{
                maxodd=max(maxodd,mp[i]);
            }
        }
        return maxodd-mineven;
    }
};