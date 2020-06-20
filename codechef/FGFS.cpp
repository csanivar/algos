#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std; 
using lint = long long;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////
int main()
{   
    int T, N, K;
    cin >> T;
    while(T--) {
        cin >> N >> K;
        // vector<int> c(K); // this can be made into a map I guess
        map<int, int> c;
        vector<pi> f(N);
        int s[N], p[N];
        int st, ft, pt;
        REP(i,N) {
            // cin >> s[i] >> ft >> p[i];
            scanf("%d %d %d", &s[i], &ft, &p[i]);
            f[i] = make_pair(ft,i);
        }
        sort(all(f));
        int ans = 0;
        REP(i,N) {
            ft = f[i].first;
            st = s[f[i].second];
            pt = p[f[i].second];
            // cout << st << " " << ft << " " << pt << endl;
            if(c.find(pt) == c.end() or c[pt] <= st) {
                c[pt] = ft;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}