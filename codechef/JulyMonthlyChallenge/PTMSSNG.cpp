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
    int T, N, x, y;
    cin >> T;
    int rx = 0, ry = 0;
    while(T--) {
        cin >> N;
        N = 4*N - 1;
        while(N--) {
            cin >> x >> y;
            rx ^= x;
            ry ^= y;
        }
        cout << rx << " " << ry << endl;
        rx = 0; ry = 0;
    }
    return 0;
}

/**
1
2
0 0
0 1
1 0
1 1
2 1
2 2
1 1
**/