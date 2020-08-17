class Solution {
public:
    bool detectCapitalUse(string word) {
        regex re("(^[A-Z]*$)|(^.[a-z]*$)");
        return regex_match(word, re);
    }
};
