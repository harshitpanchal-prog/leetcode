class Solution {
public:
    vector<int>result;
    void dfs(int startpoint ,int prev ,unordered_map<int,vector<int>>&mp){
        result.push_back(startpoint);
        for(int& v:mp[startpoint]){
            if(v!=prev){
                dfs(v,startpoint,mp);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>mp;
        for(vector<int>&vec : adjacentPairs){
            int u=vec[0];
            int v=vec[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int startpoint=-1;
        for(auto& it:mp){
            if(it.second.size()==1){
                startpoint=it.first;
                break;
            }
        }
        dfs(startpoint,INT_MIN,mp);
        return result;
    }
};