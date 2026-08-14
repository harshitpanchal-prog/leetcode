class Solution {
public:
    int n;
int m;

vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};

int dfs(vector<vector<int>>& grid, int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) {
        return 0;
    }

    int original_gold_value = grid[i][j];
    grid[i][j] = 0;

    int maxgold = 0;

    for(vector<int>& dir : directions) {
        int new_i = i + dir[0];
        int new_j = j + dir[1];

        maxgold = max(maxgold, dfs(grid, new_i, new_j));
    }

    grid[i][j] = original_gold_value;

    return original_gold_value + maxgold;
}

int getMaximumGold(vector<vector<int>>& grid) {
    int maxgold = 0;

    n = grid.size();
    m = grid[0].size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] != 0) {
                maxgold = max(maxgold, dfs(grid, i, j));
            }
        }
    }

    return maxgold;
}
};