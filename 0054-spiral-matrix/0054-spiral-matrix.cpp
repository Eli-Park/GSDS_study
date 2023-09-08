class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        int rlength = matrix.size();
        int clength = matrix[0].size();

        vector<bool> inner (clength, false);
        vector<vector<bool>> visited(rlength, inner);
        
        char d = 'h';
        int r = 0;
        int c = 0;
        int delta = 1;
        int n_fail = 0;
        while(true) {
            if (n_fail == 2) {
                break;
            }

            if (d == 'h' && c > -1 && c < clength && visited[r][c] == false) {
                output.push_back(matrix[r][c]);
                visited[r][c] = true;
                c += delta;
                n_fail = 0;
            }
            else if (d == 'h') {
                d = 'v';
                r+=delta;
                c-=delta;
                n_fail += 1;
            }
            else if (d == 'v' && r > -1 && r < rlength && visited[r][c] == false) {
                output.push_back(matrix[r][c]);
                visited[r][c] = true;
                r += delta;
                n_fail = 0;
            }
            else if (d == 'v') {
                d = 'h';
                r-=delta;
                n_fail += 1;
                delta = delta *-1;
                c+=delta;
            }           

        }
        return output;
    }
};