class CombinationIterator {
public:
    int curr, counter, maxCounter, len;
    stack<string> combis;
    int N;
    CombinationIterator(string characters, int combinationLength) {
        curr = -1;
        combis = stack<string>();
        len = characters.length();
        initCounter(combinationLength);
        // cout << counter << " " << maxCounter;
        computeCombis(characters);
        N = combis.size();
    }
    
    void initCounter(int clen) {
        counter = 0;
        for(int i=0; i<clen; ++i) {
            counter <<= 1;
            counter ^= 1;
        }
        maxCounter = counter;
        for(int i=0; i<len-clen; i++) {
            maxCounter <<= 1;
        }
    }
    
    void computeCombis(string input) {
        while(counter <= maxCounter) {
            string s = "";
            int c = counter;
            int idx = len-1;
            for(int i=0; i<len; ++i) {
                if(c&1) {
                    s = input[idx] + s;
                }
                c >>= 1;
                --idx;
            }
            combis.push(s);
            getNextCounter();
        }
    }
    
    void getNextCounter() {
        unsigned a = counter;
        unsigned c = (a & -a);
        unsigned r = a+c;
        
        counter = (((r ^ a) >> 2) / c) | r;
    }
    
    string next() {
        string s = combis.top();
        combis.pop();
        return s;
    }
    
    bool hasNext() {
        return !combis.empty();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
