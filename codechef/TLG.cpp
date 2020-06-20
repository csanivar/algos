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
int main()
{   
    int n;
    cin >> n;
    int as = 0, bs = 0, max = 0, win;
    while(n--) {
        int a, b, diff;
        cin >> a >> b;
        as += a;
        bs += b;
        diff = abs(as - bs);
        if(diff > max) {
            max = diff;
            if(as > bs) win = 1;
            else win = 2;
        }
    }
    cout << win << " " << max << endl;
    return 0;
}

vector<vector<int>> ans;

int solveIntervals(vector<int> A, vector<int> B) {
    if(A[1] < B[0]) return 1; // increment A
    if(B[1] < A[0]) return 2; // increment B
    if(A[1] < B[1]) {
        vector<int> v = {max(A[0], B[0]), A[1]};
        ans.push_back(v);
        return 1; // increment A
    }
    if(B[1] < A[1]) {
        vector<int> v = {max(A[0], B[0]), B[1]};
        ans.push_back(v);
        return 2; // increment B
    }
    if(A[1] == B[1]) {
        vector<int> v = {max(A[0], B[0]), B[1]};
        ans.push_back(v);
        return 3; // increment A and B
    }

    return -1;
}

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    int ai = 0, bi = 0;
    while(ai < A.size() and bi < B.size()) {
        int r = solveIntervals(A[ai], B[bi]);
        if(r == 1 or r == 3) ai++;
        if(r == 2 or r == 3) bi++;
        if(r == -1) {
            cout << "ERROR" << endl;
            return ans;
        }
    }

    return ans;
}

     |----------|
   |---------|

   |----------|
       |---------|

    |------|         |--------|
             |-----|  

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& b) {
    vector<vector<int>> ans;
    int id = 0, n = intervals.size();
    while(id < n and b[0] > intervals[id][0]) {
        ans.push_back(intervals[id]);
        id++;
    }

    vector<int> a;
    if(ans.size() == 0 or ans[ans.size()-1][1] < b[0]) {
        ans.push_back(b);
    } else {
        a = ans[ans.size()-1];
        a[1] = max(a[1], b[1]);
        ans[ans.size()-1] = a;
    }

    while(id < n) {
        a = intervals[id];
        vector<int> c = ans[ans.size()-1];
        if(c[1] < a[0]) {
            ans.push_back(a);
        } else {
            c[1] = max(c[1], a[1]);
            ans[ans.size()-1] = c;
        }
    }

    return ans;
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& b) {
    vector<vector<int>> ans;
    int id = 0, n = intervals.size();
    while(id < n and b[0] > intervals[id][1]) {
        ans.push_back(intervals[id++]);
    }

    while(id < n and intervals[id][0] <= b[1]) {
        // b[0] = min(b[0], intervals[id][0]);
        b[1] = max(b[1], intervals[id][1]);
        id++;
    }

    ans.push_back(b);
    
    while(id < n) {
        ans.push_back(intervals[id++]);
    }

    return ans;
}
/////////////////////

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp;
        int n = nums1.size(), m = nums2.size();
        for(int i=0; i<n; i++){
            vector<int> row;
            for(int j=0; j<m; j++) {
                row.push_back(nums1[i]*nums2[j]);
            }
            dp.push_back(row);
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i>0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if(j>0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
                if(i>0 and j>0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + max(0,nums1[i]*nums2[j]));
            }
        }

        return dp[n-1][m-1];
    }