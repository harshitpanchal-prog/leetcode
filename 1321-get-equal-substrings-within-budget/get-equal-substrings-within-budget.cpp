class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0;
        int j=0;
        int n=s.length();
        int currCost=0;
        int maxlength=0;
        while(j<n){
            currCost+=abs(s[j]-t[j]);
            while(currCost>maxCost){
                currCost-=abs(s[i]-t[i]);
                i++;
            }
            maxlength=max(maxlength,j-i+1);
            j++;
        }
        return maxlength;
    }
};