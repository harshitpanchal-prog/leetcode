class Solution {
public:
    int reverseDegree(string s) {
        //26-(ch-'a');
        int n = s.length();
        int sum = 0 ;
        for(int i=0 ; i<n ; i++){
            sum+=(i+1)*(26-(s[i]-'a'));

        }
        return sum;

    }
};