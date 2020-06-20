#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std; 
using lint = long long;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
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

void updateVal(map<int, int> &m, int val) {
    auto it = m.find(val);
    if(it == m.end()) {
        m.insert({val, 1});
    } else {
        it->second++;
    }
}

int main()
{   
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    map<int, int> m;
    int t;
    REP(i,n1+n2+n3) {
        cin >> t;
        updateVal(m, t);
    }
    vector<int> res;
    // cout << m.size() << endl;
    for(auto it=m.begin(); it!=m.end(); it++) {
        // cout << it->second << endl;
        if(it->second>=2) {
            res.push_back(it->first);
        }
    }
    // sort(all(res));
    cout << sz(res) << endl;
    REP(i,sz(res)) {
        cout << res[i] << endl;
    }
    return 0;
}