class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.length();
        int diffs=0;
        int first_diff=0;
        int second_diff=0;
        for(int i=0 ; i<n ; i++){
            if(s1[i] != s2[i]){
                diffs++;
                if(diffs > 2){
                    return false;
                }else if(diffs == 1){
                    first_diff=i;
                }else{
                    second_diff=i;
                }
            }
        }
        return s1[first_diff] == s2[second_diff] && s1[second_diff] == s2[first_diff];
    }
};