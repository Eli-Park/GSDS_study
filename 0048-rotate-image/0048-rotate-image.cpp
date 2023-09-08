class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        matrix = flip(matrix);
        matrix = transpose(matrix);
        
    }

    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int length = matrix.size();
        int temp = 0;
        for (int i = 0; i < length; i++) {
            for(int j = i+1; j < length; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        return matrix;

    }

    vector<vector<int>> flip(vector<vector<int>>& matrix) {
        int length = matrix.size();
        vector<int> temp(length);
        for (int i = 0; i < length/2; i++) {
                temp = matrix[i];
                matrix[i] = matrix[length-1-i];
                matrix[length-1-i] = temp;
        }
        return matrix;

    }
};