#define REP(i,N) for(int i=0; i<N; ++i)

class Solution {
public:
    int N, M;
    bool isValid(int i, int j) {
        return i>=0 and j>=0 and i<N and j<M;
    }

    int getFreshOrangesCount(vector<vector<int>>& grid) {
        int cnt = 0;
        REP(i,N) {
            REP(j,M) {
                if(grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();
        int dirs[4][2] = {{1, 0},{-1, 0},{0, -1},{0, 1}};
        int ans = 0;
        int foc;
        foc = getFreshOrangesCount(grid);
        // cout << foc << endl;
        while(foc != 0) {
            ++ans;
            vector<vector<int>> og = grid;
            REP(i,N) {
                REP(j,M) {
                    if(og[i][j] == 1) {
                        for(auto dir: dirs) {
                            int x = i + dir[0], y = j + dir[1];
                            // cout << x << " " << y << " " << isValid(x,y) << endl;
                            if(isValid(x, y) and og[x][y] == 2) grid[i][j] = 2;
                        }
                    }
                }
            }
            int cfoc = getFreshOrangesCount(grid);
            // cout << cfoc << endl;
            if(cfoc == foc) return -1;
            foc = cfoc;
        }
        
        return ans;
    }
};
