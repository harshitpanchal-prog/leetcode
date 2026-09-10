class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int result = 0;
        vector<int>vec(100);
        for(auto& d : dominoes){
            if(d[0]>d[1]){
                swap(d[0],d[1]);
            }
            int num = d[0]*10+d[1];
            result+=vec[num];
            vec[num]++;
        }
        return result;
    }
};