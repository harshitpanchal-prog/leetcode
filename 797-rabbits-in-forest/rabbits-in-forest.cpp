class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        for(int &num : answers){
            mp[num]++;
        }
        int total=0;
        for(auto & it:mp){
            int x=it.first;
            int count=it.second;
            int groupsize=(x+1);
            int groups=ceil((double)count/groupsize);
            total+=groups*groupsize;
        }
        return total;
    }
};