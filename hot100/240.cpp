class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i=0, j= n-1;
        while(true){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] < target) i++;
            else j--;
            if(i<0 || i>=m) break;
            if(j<0 || j>=n) break;
        }
        return false;
    }
};