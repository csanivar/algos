#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
 
vector<pi> pr;
 
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
	int n = A.size();
    if(n==1) return 1;
	int p = 0;
	int maxLen = 0;
	while(p < n) {
		int p1 = p, p2 = p+1;
		while(p2+2<n and A[p1]==A[p1+2] and A[p2]==A[p2+2]) {
			p1 += 2;
			p2 += 2;
		}
		if(p1+2<n and A[p1]==A[p1+2]) {
			p1 += 2;
		}
		int m = max(p1, p2);
		maxLen = max(maxLen, m-p+1);
		p = m;
	}

	return maxLen;
}

vector<vector<int>> visited;


int dfs(vector<vector<int>> &A, int x, int y, int color) {
    if(x<0 or x>=A.size() or y<0 or y>=A[0].size()) return 0;
    if(visited[x][y] == 1) return 0;
    if(A[x][y] == color) {
        visited[x][y] = 1;
        int dn = dfs(A, x, y-1, color);
        int de = dfs(A, x+1, y, color);
        int dw = dfs(A, x-1, y, color);
        int ds = dfs(A, x, y+1, color);
        return 1+dn+de+dw+ds;
    }
    return 0;
}

void dfs2(vector<vector<int>> &A, int x, int y, int color) {
    if(x<0 or x>=A.size() or y<0 or y>=A[0].size()) return;
    if(visited[x][y] == 1) return;
    if(A[x][y] == color) {
        visited[x][y] = 1;
        dfs2(A, x, y-1, color);
        dfs2(A, x+1, y, color);
        dfs2(A, x-1, y, color);
        dfs2(A, x, y+1, color);
    }
}

int solution1(vector<vector<int>> &A) {
    int n = A.size(), m = A[0].size();
    for(int i=0; i<n; i++) {
        vector<int> row;
        for(int j=0; j<m; j++) {
            row.push_back(0);
        }
        visited.push_back(row);
    }

    int count = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(visited[i][j] == 0) {
                    count++;
                dfs2(A, i, j, A[i][j]);
            }
        }
    }

    return count;
}


// [[5, 4, 4], [4, 3, 4], [3, 2, 4], [2, 2, 2], [3, 3, 4], [1, 4, 4], [4, 1, 1]]

int main(){
    int N;
    vector<int> in;
    cin >> N;
    while(N--) {
        int i;
        cin >> i;
        in.push_back(i);
    }
    cout << solution(in) << endl;
    // int n, m;
    // cin >> n >> m;
    // vector<vector<int>> A;
    // for(int i=0; i<n; i++) {
    //     vector<int> row;
    //     for(int j=0; j<m; j++) {
    //         int t;
    //         cin >> t;
    //         row.push_back(t);
    //     }
    //     A.push_back(row);
    // }
    // cout << solution1(A) << endl;
    return 0;
}

public:
    void insertIntoMap(map<int, vector<int> &mp, int x, int y) {
        auto c = mp.find(x);
        if(c == mp.end()) {
            mp.insert({x, vector<int> v{y}});
        } else {
            c->second.push_back(y);
        }
    }

    map<int, int> mp;
    vector<vector<int>> graph;
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        for(int i=0; i<N+1; i++) {
            graph.push_back(new vector<int>());
        }
        for(vector<int> d: dislikes) {
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }

        map<int, int> colormap;
        for(int i=1; i<=N; i++) {
            if(mp.find(i)==mp.end() and dfs(i, 0)) {
                return false;
            }
        }

        return true;
    }

    bool dfs(int node, int color) {
        if(mp.find(node)!=mp.end()) {
            return mp[node] == color;
        }
        mp.insert({node, color});
        for(int i: graph[node]) {
            if(!dfs(node, c^1)) {
                return false;
            }
        }

        return true;
    }

public:
    vector<int> countBits(int num) {
        vector<int> ans = 0;
        ans.push_back(0);
        if(num == 0) return ans;
        ans.push_back(1);
        if(num == 1) return ans;
        int j = 1;
        for(int i=2; i<INT_MAX; i++) {
            if((i & (i-1)) == 0) {
                ans.push_back(1);
                j = 1;
            } else {
                ans.push_back(1+ans[j]);
                j++;
            }
            if(i == num) break;
        }

        return ans;
    }

public:
    vector<vector<int>> graph;
    vector<bool> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0; i<numCourses; i++) {
            graph.push_back(new vector<int>);
            visited.push_back(false);
        }

        for(vetor<int> prereq: prerequisites) {
            graph[prereq[0]].push_back(prereq[1]);
        }

        queue<int> qu;
        for(int i=0; i<numCourses; i++) {
            if(visited[i]) continue;
            qu.push_back(i);
            while(!qu.empty()) {
                int t = qu.front();
                if(visited[t]) return false;
                visited[t] = true;
                for(int pre: graph[t]) {
                    queue.push_back(pre);
                }
            }
        }

        return true;
    }


public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        vector<vector<int>> dp(n1, vector<int>(n2, 0));

        for(int i=0; i<n1; i++) {
            for(int j=0; j<n2; j++) {
                if(word1[i] == word2[j]) dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = 1 + min(dp[i-1][j-1], d[i][j-1], dp[i-1][j]);
                }
            }
        }

        return dp[n1-1][n2-1];
    }