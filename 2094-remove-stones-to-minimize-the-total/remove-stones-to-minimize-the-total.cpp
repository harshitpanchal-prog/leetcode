class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int>pq;
        int sum=0;

        for(int i=0 ; i<n ;i++){
            pq.push(piles[i]);
            sum+=piles[i];
        }

        while(k--){
            int max_el = pq.top();
            pq.pop();
            int remove = max_el/2;

            sum-=remove;
            max_el-=remove;
            pq.push(max_el);
        }
        return sum;
    }
};