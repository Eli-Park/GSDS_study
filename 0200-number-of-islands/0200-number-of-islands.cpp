class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int output = 0;
        int m = grid.size() ;
        int n = grid[0].size();
        vector<vector<bool>> visited (m, vector<bool> (n, false));

        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (grid[i][j] == '1' & visited[i][j] == false ) {
                    DFS(grid, visited, i, j);
                    output +=1 ;
                }
            }
        }
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
            cout<<visited[i][j]<<" ";
            }
            cout<<endl;
        }

        return output;
        
    }

    void DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int m, int n) {
        
        if (grid[m][n] == '1' & visited[m][n] == false) {
            visited[m][n] = true;
            if (m+1 < grid.size()) {
                DFS(grid, visited, m+1, n);
            }
            if (m-1 >= 0) {
                DFS(grid, visited, m-1, n);
            }
            if (n+1 < grid[0].size())  {
                DFS(grid, visited, m, n+1);
            }
            if (n-1 >= 0) {
                DFS(grid, visited, m, n-1);
            }

        }
    }
};