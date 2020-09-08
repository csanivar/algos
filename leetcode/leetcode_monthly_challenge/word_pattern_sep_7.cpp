class Solution {
public:
    bool wordPattern(string pattern, string str) {
        string m1[26];
        for(int i=0; i<26; ++i) m1[i] = "";
        map<string, int> m2;
        istringstream iss(str);
        vector<string> words((istream_iterator<string>(iss)), istream_iterator<string>());
        if(words.size() != pattern.length()) return false;
        for(int i=0; i<words.size(); ++i) {
            string word = words[i];
            int idx = pattern[i] - 'a';
            if(m2.find(word) == m2.end()) {
                if(m1[idx] != "") return false;
                m2[word] = idx;
                m1[idx] = word;
            } else if(word != m1[m2[word]] or m2[word] != idx) {
                return false;
            }
        }
        
        return true;
    }
};
