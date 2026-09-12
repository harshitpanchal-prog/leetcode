class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int oddcount=0;
        for(int i=0 ; i<n ; i++){
            if(arr[i]%2 ==1){
                oddcount++;
            }else{
                oddcount = 0;
            }
            if(oddcount == 3){
                return true;
            }
        }
        return false;
    }
};