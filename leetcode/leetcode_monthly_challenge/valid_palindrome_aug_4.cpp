class Solution {
public:
    
    char getchar(char c) {
        int ca = c - 'a';
        int cA = c - 'A';
        int ci = c - '0';
        
        if(ca>=0 and ca <=25) return c;
        if(cA>=0 and cA <=25) return (char)c-'A'+'a';
        if(ci>=0 and ci <=9) return c;
        
        return NULL;
    }
    
    bool isPalindrome(string s) {
        string t = "";
        for(auto c: s) {
            if(getchar(c) != NULL) t += getchar(c);
        }
        cout << t;
        int lo = 0, hi = t.length()-1;
        while(lo < hi) {
            if(t[lo] != t[hi]) return false;
            ++lo;
            --hi;
        }
        return true;
    }
};
