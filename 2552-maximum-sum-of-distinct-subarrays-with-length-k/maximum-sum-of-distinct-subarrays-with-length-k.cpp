class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int>st;
        long long result=0;
        long long cumulativeSum=0;
        int i=0;
        int j=0;
        while(j<n){
            while(st.count(nums[j])){
                cumulativeSum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
            cumulativeSum+=nums[j];
            st.insert(nums[j]);
            if(j-i+1 == k){
                result=max(result,cumulativeSum);
                cumulativeSum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
            
            j++;
        }
        return result;

    }
};