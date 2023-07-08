class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int min = 0;
        int max = matrix.size()-1;
        int med;
        while (min <= max) {
            med = (max + min) / 2;
            if (matrix[med][0] == target) {
                return true;
            }

            else if (matrix[med][0] < target) {
                min = med + 1;
                if (med+1 < matrix.size() && matrix[med+1][0] > target) {

                    break;
                }
            }
            else {
                max = med - 1;
            }
        }

        min = 0;
        max = matrix[med].size()-1;
        int col_med;
        while (min <= max ) {
            col_med = (max + min) / 2;
            if (matrix[med][col_med] == target) {
                return true;
            }

            else if (matrix[med][col_med] < target) {
                min = col_med + 1;
            }
            else {
                max = col_med - 1;
            }
        }

        return false;

        
    }
};