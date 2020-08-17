class Solution {
public:
    
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(auto c: s) {
            mp[c] += 1;
        }
        int ans = 0, carry = 0;
        for(auto item: mp) {
            ans += (item.second/2)*2;
            if(item.second % 2 == 1) carry = 1;
        }
        return ans + carry;
    }
};
