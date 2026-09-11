class Solution {
public:
    
    string reorganizeString(string s) {
        int n=s.length();
        vector<int> count(26,0);
        int maxfreq = 0;
        int charmaxfreq;
        for(char& ch : s){
            count[ch-'a']++;
            if(count[ch-'a']>maxfreq){
                maxfreq = count[ch-'a'];
                charmaxfreq = ch;
            }
            if(count[ch-'a']>(n+1)/2){
                return "";
            }
        }

        string result=s;
        int i=0;
        while(count[charmaxfreq-'a']>0){
            result[i] = charmaxfreq;
            i+=2;
            count[charmaxfreq-'a']--;
        }
        for(char ch='a' ; ch<='z' ; ch++){
            while(count[ch-'a']>0){
                if(i>=n){
                    i=1;
                }
                result[i]=ch;
                i+=2;
                count[ch-'a']--;
            }
        }
        return result;
    }
};