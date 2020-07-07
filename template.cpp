#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;

typedef long long ll;
using pi = pair<int, int>;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<int> row(h, 0), col(w, 0);
    vector<vector<char>> board;
    char c;
    int tot = 0;
    REP(i,0,h-1) {
        vector<char> r;
        REP(j,0,w-1) {
            cin >> c;
            r.push_back(c);
            if (c == '#') {
                row[i]++;
                col[j]++;
                tot++;
            }
        }
        board.push_back(r);
    }
    if(tot < k) {
        cout << 0 << endl;
        return 0;
    }
    int ans = k == tot ? 1 : 0;
    REP(i, 0, h-1) {
        if(tot - row[i] == k) ans++;
    }
    REP(j, 0, w-1) {
        if(tot - col[j] == k) ans++;
    }
    REP(i, 0, h-1) {
        int cnt = row[i];
        REP(j, 0, w-1) {
            cnt += col[j] - (board[i][j] == '#' ? 1 : 0);
            if(tot - cnt == k) break;
        }
        if (tot - cnt == k) ans++;
    }
    REP(i, 0, h-1) {
        int cnt = row[i];
        REP(j, 0, w-1) {
            cnt += col[j] - (board[i][j] == '#' ? 1 : 0);
            if(tot - cnt == k) break;
        }
        if (tot - cnt == k) ans++;
    }
    REP(j, 0, w-1) {
        int cnt = col[j];
        int rcnt = 0;
        REP(i, 0, h-1) {
            rcnt++;
            cnt += row[i] - (board[i][j] == '#' ? 1 : 0);
            if(tot - cnt == k) break;
        }
        if (tot - cnt == k && rcnt != 1) ans++;
    }
    cout << ans << endl;
    return 0;
}
