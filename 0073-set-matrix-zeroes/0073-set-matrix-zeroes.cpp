class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows;
        vector<int> cols;

        //0이 있는 row나 col index
        for (int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j <matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        //중복 제거
        auto newrowEnd = std::unique(rows.begin(), rows.end());
        rows.erase(newrowEnd, rows.end());

        auto newcolEnd = std::unique(cols.begin(), cols.end());
        cols.erase(newcolEnd, cols.end());       

        int row = 0;
        int row_zero = 0;
        for (auto ele : rows) {
            cout<<ele<<endl;
        }
        //row에 zero가 있는 경우, 0으로 채워진 vector로 해당 row 대체
        //col에 zero가 있는 경우, 해당 element 0으로 대체
        while (row < matrix.size()) {
            if (row_zero < rows.size() && row == rows[row_zero] ) {
                vector<int> temp (matrix[0].size(), 0);
                matrix[row] = temp;
                row += 1;
                row_zero +=1;
                continue;
            }
            else {
                for(auto zero_col : cols) {
                    matrix[row][zero_col] = 0;
                }
                row +=1;
            }

        }
        
    }
};