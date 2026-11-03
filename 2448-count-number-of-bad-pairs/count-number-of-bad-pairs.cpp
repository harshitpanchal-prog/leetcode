class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long result=0;
        
        unordered_map<int,int>mp;
        
        for(int j=0 ; j<n ; j++){
            int diff=nums[j]-j;
            int goodpair=mp[diff];
            int totalpairsinpast=j;
            result+=totalpairsinpast-goodpair;
            mp[diff]++;
        }
        return result;
    }
};