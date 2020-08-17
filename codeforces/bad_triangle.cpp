#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define REP(i,a,b) for (int i = a; i < b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;

typedef long long ll;
using pi = pair<int, int>;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        REP(i,0,n) {
            cin >> a[i];
        }
        if(a[0]+a[1]<=a[n-1]) cout << "1 2 " << n << endl;
        else cout << -1 << endl;
    }
}
