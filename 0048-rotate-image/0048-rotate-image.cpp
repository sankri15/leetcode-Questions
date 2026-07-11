class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // row & col size
        int row = matrix.size();
        int col = matrix[0].size();

        // take transpose (in place)
        for(int i=0; i<row; i++){
            for(int j=i+1; j<col; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse every row (in place)
        for(int i=0; i<row; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};