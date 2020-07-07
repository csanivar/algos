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
    int a[8][8];
    int T, k;
    cin >> T;
    while(T--) {
        cin >> k;
        int cnt = 0;
        REP(i, 0, 7) {
            REP(j, 0, 7) {
                if(cnt >= k) {
                    a[i][j] = -1;
                } else {
                    cnt++;
                    a[i][j] = 0;
                }
            }
        }
        a[0][0] = 2;
        REP(i, 0, 7) {
            REP(j, 0, 7) {
                if(a[i][j] == 2) {
                    cout << "O";
                } else if(a[i][j] == 0) {
                    cout << ".";
                } else if(a[i][j] == -1) {
                    cout << "X";
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}