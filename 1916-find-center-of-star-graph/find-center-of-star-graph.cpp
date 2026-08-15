class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> degree;
        for(auto &vec: edges){
            int first = vec[0];
            int second = vec[1];
            degree[first]++;
            degree[second]++;
        }
        for(auto &it : degree){
            if(it.second==edges.size()){
                return it.first;
            }
        }
        return -1;
    }
};