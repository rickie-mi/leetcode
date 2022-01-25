int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1) return matrix[0][0];
        vector<vector<int>> path(n, vector<int>(n));
        for(int i=0; i<n; i++) 
            path[0][i] = matrix[0][i]; //第一行都是原来的
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                path[i][j] = matrix[i][j]+path[i-1][j];
                if(j-1>=0) path[i][j] = min(path[i][j], matrix[i][j] + path[i-1][j-1]);
                if(j+1<n) path[i][j] = min(path[i][j], matrix[i][j] + path[i-1][j+1]);
            }
        }
        int res = INT_MAX;
        for(int i=0; i<n; i++)
            res = min(res, path[n-1][i]);
        return res;
}