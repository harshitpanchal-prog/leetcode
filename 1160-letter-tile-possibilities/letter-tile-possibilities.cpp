class Solution {
public:
    int n;
    void solve(string tiles , unordered_set<string> &result , vector<bool>&used , string&curr ){
        result.insert(curr);
        for(int i=0 ; i<n ; i++){
            if(used[i]){
                continue;
            }
            used[i] = true;
            curr.push_back(tiles[i]);
             
            solve(tiles,result,used,curr);
            used[i] = false;
            curr.pop_back();
        }
    }


    int numTilePossibilities(string tiles) {
        n= tiles.length();
        unordered_set<string> result;
        vector<bool> used(n,false);
        string curr="";
        solve(tiles,result,used,curr);
        return result.size() - 1;
    }
};