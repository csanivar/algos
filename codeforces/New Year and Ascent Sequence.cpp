#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std; 
using lint = long long;
using pi = pair<int, int>;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////

vector<pi> pr;

int main()
{
    int n;
    cin >> n;
    lint ans = n * n;
    REP(i,n) {
        int l;
        cin >> l;
        vector<int> v(l);
        REP(j,l) {
            cin >> v[j]
        }
        reverse(all(v));
        if(is_sorted(all(v))) {
            pr.emplace_back(v[0], v.back());
        }
    }
    sort(all(pr));
    REP(i,sz(pr)) {
        ans -= pr.end() - lower_bound(all(pr), pi(pr[i].second, -1));
    }
    cout << ans << endl;
    return 0;
}