class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string s1;
        string s2;
        for(int i=0 ; i<n; i++){
            if(i==n-1){
                s1.push_back('.');
            }else{
                s1.push_back('#');
            }
        }
        for(int i=0 ; i<n ; i++){
            s2.push_back('.');
        }
        vector<string>result;
        result.push_back(s2);
        while(result.size()<m){
            result.push_back(s1);
        }
        return result;
    }
};