class Solution {
public:
    int count;
    void solve(vector<int>& freq){
        count++;
        for(int i = 0 ; i < 26 ; i++){
            if(freq[i]==0){
                continue;
            }
            freq[i]--;
            solve(freq);
            freq[i]++;
        }
    }


    int numTilePossibilities(string tiles) {
        count = 0;
        vector<int> freq(26,0);
        for(char& ch : tiles){
            freq[ch-'A']++;
        }
        solve(freq);
        return count-1;    
        
        
    }
};