#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
 
vector<pi> pr;
 
int main(){
	int n;
    cin >> n;
    vector<int> v;
    while(n-->0) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(auto c: v) {
        cout << c << " ";
    }
}

