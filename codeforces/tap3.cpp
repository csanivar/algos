#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bitset<26> gethash(string word) {
    bitset<26> res;
    for(char c: word) {
        res[c-'a'] = 1;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string w;
    cin >> w;
    bitset<26> bw = gethash(w);
    int count = 0;
    string word;
    set<string> st;
    bitset<26> bl;
    while(cin >> word) {
        if(st.count(word) != 0) continue;
        st.insert(word);
        bl = gethash(word);
        if(bl == bw) {
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}
