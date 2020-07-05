class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) return 1;
        int l1 = 0, l2 = 0, l3 = 0;   
        vector<int> val;
        val.push_back(1);
        n--;
        while(n--) {
            int a1 = val[l1]*2;
            int a2 = val[l2]*3;
            int a3 = val[l3]*5;
            int rs = min(a1, min(a2, a3));
            if(rs == a1) l1++;
            if(rs == a2) l2++;
            if(rs == a3) l3++;
            val.push_back(rs);
        }
        
        return val[val.size()-1];
    }
};
