class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int>result;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rowMin(n);
        vector<int> colMax(m);
        for(int row = 0 ; row < n ; row ++){
            int minEl = INT_MAX;
            for(int col = 0; col < m ; col ++){
                minEl=min(minEl,matrix[row][col]);
            }
            rowMin[row] = minEl;
        }
        for(int col = 0 ; col < m ; col++){
            int maxEl=INT_MIN;
            for(int row = 0 ; row < n ; row ++){
                maxEl=max(maxEl,matrix[row][col]);
            }
            colMax[col] = maxEl;
        }
        for(int row = 0 ; row < n ; row++){
            for(int col =0 ; col < m ; col++){
                if(matrix[row][col] == colMax[col] && matrix[row][col] == rowMin[row]){
                    result.push_back(matrix[row][col]);
                }
            }
        }
        return result;
    }
};