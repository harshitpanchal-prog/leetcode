class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count=0;
        int mask=0;
        for(char& ch : allowed){
            mask |= (1<<(ch-'a'));
        }
        for(string& word : words){
            bool allcharacterallowed=true;
            for(char& ch : word){
                if(((mask>>(ch-'a')) & 1) == 0 ){
                    allcharacterallowed = false;
                    break;
                }
            }
            if(allcharacterallowed){
                count++;
            }
        }
        return count;
    }
};