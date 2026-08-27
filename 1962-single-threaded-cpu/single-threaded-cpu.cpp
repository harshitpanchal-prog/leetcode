class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<array<int,3>>sortedtasks;
        for(int i=0 ; i<n ; i++){
            int start_time=tasks[i][0];
            int task_duration=tasks[i][1];
            sortedtasks.push_back({start_time,task_duration,i});
        }

        sort(begin(sortedtasks),end(sortedtasks));
        vector<int>result;
        long long current_time=0;
        int idx = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;

        while(idx<n || !pq.empty()){
            if(pq.empty() && current_time < sortedtasks[idx][0]){
                current_time = sortedtasks[idx][0];
            }
            while(idx<n && sortedtasks[idx][0] <= current_time){
                pq.push({sortedtasks[idx][1],sortedtasks[idx][2]});
                idx++;
            }
            pair<int,int>curr_task = pq.top();
            pq.pop();
            current_time += curr_task.first;
            result.push_back(curr_task.second);
        }
        return result;
    }
};