class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxEl= *max_element(begin(nums),end(nums));
        int n=nums.size();
        int i=0;
        int j=0;
        long long result=0;
        int countmax=0;
        while(j<n){
            if(nums[j]==maxEl){
                countmax++;
            }
            while(countmax >=k){
                result+=n-j;
                if(nums[i]==maxEl){
                    countmax--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};