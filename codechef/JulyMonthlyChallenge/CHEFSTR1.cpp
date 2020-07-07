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
    int T, N, s1, s2;
    cin >> T;
    while (T--) {
        cin >> N;
        long ans = 0;
        cin >> s1;
        N--;
        while(N--) {
            cin >> s2;
            ans += abs(s2-s1)-1;
            // cout << ans << " ";
            s1 = s2;
        }
        cout << ans << endl;
    }
    return 0;
}