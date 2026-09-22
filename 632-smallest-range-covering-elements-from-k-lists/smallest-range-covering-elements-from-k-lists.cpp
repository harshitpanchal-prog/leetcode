class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k= nums.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int maxel=INT_MIN;
        for(int i=0 ; i<k ; i++){
            pq.push({nums[i][0],i,0});
            maxel=max(maxel,nums[i][0]);
        }
        vector<int>resultrange={-1000000,1000000};
        while(!pq.empty()){
            vector<int>curr = pq.top();
            pq.pop();
            int minel=curr[0];
            int listidx=curr[1];
            int idx=curr[2];
            if(maxel-minel < resultrange[1]-resultrange[0]){
                resultrange[0]=minel;
                resultrange[1]=maxel;
            }
            if(idx+1 < nums[listidx].size()){
                int nextelement = nums[listidx][idx+1];
                pq.push({nextelement,listidx,idx+1});
                maxel=max(maxel,nextelement);
            }else{
                break;
            }
        }
        return resultrange;
    }
};