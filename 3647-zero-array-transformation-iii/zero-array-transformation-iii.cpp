class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int Q=queries.size();
        priority_queue<int>pq;
        priority_queue<int,vector<int>,greater<int>>past;

        sort(begin(queries),end(queries));
        int j=0;
        int usedcount=0;

        for(int i=0 ; i<n ; i++){
            while(j<Q && queries[j][0]==i){
                pq.push(queries[j][1]);
                j++;
            }
            nums[i]-=past.size();
            while(nums[i]>0 && !pq.empty() && pq.top()>=i){
                int ending=pq.top();
                pq.pop();
                past.push(ending);
                usedcount++;
                nums[i]--;
            }
            if(nums[i]>0){
                return -1;
            }
            while(!past.empty() && past.top()<=i){
                past.pop();
            }
        }
        return Q-usedcount;
    }
};