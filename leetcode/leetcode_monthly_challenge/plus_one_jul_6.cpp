class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry = 1, temp = 0;
        for(int i=digits.size()-1; i>=0; i--) {
            temp = carry + digits[i];
            carry = temp/10;
            temp %= 10;
            res.insert(res.begin(), 1, temp);
        }
        if(carry>0) res.insert(res.begin(), 1, carry);
        
        return res;
    }
};
