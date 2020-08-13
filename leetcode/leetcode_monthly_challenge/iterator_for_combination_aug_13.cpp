class CombinationIterator {
public:
    int curr, counter, maxCounter, len;
    vector<string> combis;
    int N;
    CombinationIterator(string characters, int combinationLength) {
        curr = -1;
        combis = vector<string>();
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
            combis.insert(combis.begin(), s);
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
        curr++;
        return combis[curr];
    }
    
    bool hasNext() {
        return curr < N-1;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
