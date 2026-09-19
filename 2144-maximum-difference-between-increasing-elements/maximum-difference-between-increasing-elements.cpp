class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int minelement = nums[0];
        int maxdiff = -1;
        for(int i=1 ; i<n ; i++){
            if(nums[i]>minelement){
                maxdiff=max(maxdiff,nums[i]-minelement);
            }else{
                minelement=nums[i];
            }
        }
        return maxdiff;
    }
};