class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int minEl=INT_MAX;
        int maxEl=INT_MIN;
        for(int &num : nums){
            mp[num]++;
            minEl=min(minEl,num);
            maxEl=max(maxEl,num);
        }
        int i=0;
        for(int num=minEl ; num<=maxEl ; num++){
            while(mp[num]>0){
                nums[i]=num;
                i++;
                mp[num]--;

            }
        }
        return nums;
    }
};