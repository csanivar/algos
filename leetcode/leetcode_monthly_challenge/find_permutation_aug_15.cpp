class Solution {
public:
    vector<int> findPermutation(string s) {
        /*
        int N = s.size();
        vector<int> ans(N+1, 0);
        int j = 0;
        stack<int> st;
        for(int i=1; i<=N; ++i) {
            if(s[i-1] == 'I') {
                st.push(i);
                while(!st.empty()) {
                    ans[j++] = st.top();
                    st.pop();
                }
            } else {
                st.push(i);
            }
        }
        st.push(N+1);
        while(!st.empty()) {
            ans[j++] = st.top();
            st.pop();
        }
        return ans;
        */
        int N = s.size();
        vector<int> ans(N+1, 0);
        ans[0] = 1;
        int i = 1;
        while(i<=N) {
            ans[i] = i+1;
            int j = i;
            if(s[i-1] == 'D') {
                while(i<=N and s[i-1] == 'D') i++;
                for(int k=j-1, c=i; k<=i-1;k++,c--) {
                    ans[k] = c;
                }
            } else {
                i++;
            }
            
        }
        return ans;
    }
};
