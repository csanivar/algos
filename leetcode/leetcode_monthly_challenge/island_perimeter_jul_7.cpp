class Solution {
public:
    
    bool isValid(int x, int y, int N, int M) {
        return x >= 0 and y >= 0 and x < N and y < M;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int N = grid.size();
        if(N==0) return 0;
        int M = grid[0].size();
        int ans = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(grid[i][j] == 1) {
                    if(!isValid(i+1, j, N, M) or (isValid(i+1, j, N, M) and grid[i+1][j] == 0)) ans++;
                    if(!isValid(i-1, j, N, M) or (isValid(i-1, j, N, M) and grid[i-1][j] == 0)) ans++;
                    if(!isValid(i, j-1, N, M) or (isValid(i, j-1, N, M) and grid[i][j-1] == 0)) ans++;
                    if(!isValid(i, j+1, N, M) or (isValid(i, j+1, N, M) and grid[i][j+1] == 0)) ans++;
                }
            }
        }
        
        return ans;
    }
};
