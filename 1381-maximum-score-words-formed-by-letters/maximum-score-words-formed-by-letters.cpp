class Solution {
public:
    int n;
    int maxScore;
    void solve(int i,vector<int>&freq,vector<string>&words,vector<int>&score,int currScore){
        maxScore=max(maxScore,currScore);
        if(i >= n){
            return;
        }
        int tempScore=0;
        int j=0;
        vector<int> tempfreq=freq;
        while(j<words[i].length()){
            char ch=words[i][j];
            tempfreq[ch-'a']--;
            tempScore+=score[ch-'a'];
            if(tempfreq[ch-'a']<0){
                break;
            }
            j++;
        }
        if(j==words[i].length()){
            solve(i+1,tempfreq,words,score,currScore+tempScore);
        }
        solve(i+1,freq,words,score,currScore);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26,0);
        maxScore=INT_MIN;
        for(char&ch:letters){
            freq[ch-'a']++;
        }
        n=words.size();
        solve(0,freq,words,score,0);
        return maxScore;
    }
};