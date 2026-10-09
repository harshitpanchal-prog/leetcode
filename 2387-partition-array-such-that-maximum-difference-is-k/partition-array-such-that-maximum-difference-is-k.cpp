class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int count=1;
        int minval=nums[0];
        int n=nums.size();
        
        for(int i=1 ; i<n ; i++){
            if(nums[i]-minval > k){
                count++;
                minval=nums[i];
            }
        }
        return count;
    }
};