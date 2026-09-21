class Solution {
public:
    typedef pair<int,int>P;
    int M=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        priority_queue<P,vector<P>,greater<P>>pq;
        for(int i=0 ; i<n ; i++){
            pq.push({nums[i],i});
        }
        int result=0;
        for(int count=1 ; count<=right ; count++){
            auto p=pq.top();
            pq.pop();
            int idx = p.second;
            int sum = p.first;
            if(count>=left){
                result=(result+sum)%M;
            }
            if(idx+1 <n){
                pq.push({sum+nums[idx+1],idx+1});
            }
        }
        return result;
    }
};