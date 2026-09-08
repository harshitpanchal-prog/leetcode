class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        int i=0;
        int j=2;
        while(j<n){
            if(2*(nums[i]+nums[j]) == nums[j-1]){
                result++;
            }
            i++;
            j++;
        }
        return result;
    }
};