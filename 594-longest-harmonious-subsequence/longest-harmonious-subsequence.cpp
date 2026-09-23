class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        int result = 0;
        for(int &num : nums){
            mp[num]++;
        }
        for(int &num : nums){
            int minnum=num;
            int maxnum=num+1;
            if(mp.count(maxnum)){
                result=max(result,mp[minnum]+mp[maxnum]);
            }
        }
        return result;
    }
};