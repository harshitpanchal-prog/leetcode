class Solution {
public:
    typedef long long ll;
    int countKConstraintSubstrings(string s, int k) {
        ll count_0=0;
        ll count_1=0;
        int i=0;
        int j=0;
        int n=s.length();
        ll result=0;
        while(j<n){
            if(s[j]=='0'){
                count_0++;
            }else{
                count_1++;
            }
            while(count_0>k && count_1>k){
                if(s[i]=='0'){
                    count_0--;
                }else{
                    count_1--;
                }
                i++;
            }
            
            result+=j-i+1;
            j++;
        }
        return result;
    }
};