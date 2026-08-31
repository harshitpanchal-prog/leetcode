class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        long long N=n*n;
        
        long long gridSum = 0;
        long long gridsqSum = 0;

        for(int i =0 ; i<n ;i++){
            for(int j=0 ; j<n ; j++){
                gridSum+=grid[i][j];
                gridsqSum+=grid[i][j]*grid[i][j];
            }
        }

        long long sum = (N*(N+1))/2;
        long long sqsum = (N*(N+1)*(2*N+1))/6;

        int sqdiff = gridsqSum - sqsum;
        int sumdiff = gridSum - sum;

        int a = (sqdiff/sumdiff+sumdiff)/2;
        int b = (sqdiff/sumdiff-sumdiff)/2;

        return {a,b};
    }
};