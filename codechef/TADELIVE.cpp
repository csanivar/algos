#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
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
    int n, x, y;
    cin >> n >> x >> y;
    int a[n], b[n];
    vector<pi> c(n);
    REP(i,n) {
        cin >> a[i];
    }
    REP(i,n) {
        cin >> b[i];
    }
    REP(i,n) {
        c[i] = make_pair(abs(a[i]-b[i]),i);
    }
    sort(all(c));
    reverse(all(c));
    int sum = 0;
    REP(i,n) {
        int index = c[i].second;
        if(a[index] > b[index]) {
            if (x!=0) {
                sum += a[index];
                x--;
            } else {
                sum += b[index];
                y--;
            }
        } else {
            if (y!=0) {
                sum += b[index];
                y--;
            } else {
                sum += a[index];
                x--;
            }
        }
    }
    cout << sum << endl;
    return 0;
}