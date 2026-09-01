class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<bool>paired(501,true);
        for(int& num:nums){
            paired[num] = !paired[num];
        }
        for(int i=0 ; i<501 ; i++){
            if(paired[i] == false){
                return false;
            }
        }
        
        return true;;
    }
};