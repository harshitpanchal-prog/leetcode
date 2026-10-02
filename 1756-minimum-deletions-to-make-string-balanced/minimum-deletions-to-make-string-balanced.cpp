class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        vector<int>right_a(n,0);
        int counta=0;
        for(int i=n-1 ; i>=0 ; i--){
            right_a[i]=counta;
            if(s[i]=='a'){
                counta++;
            }
        }
        int count=INT_MAX;
        int countb=0;
        for(int i=0 ; i<n ; i++){
            count=min(count,countb+right_a[i]);
            if(s[i]=='b'){
                countb++;
            }
        }
        return count;
    }
};