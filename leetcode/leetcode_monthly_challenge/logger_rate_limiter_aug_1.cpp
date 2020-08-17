using pi = pair<int, string>;

class Logger {
public:
    /** Initialize your data structure here. */
    queue<pi> qu;
    set<string> entries;
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while(!qu.empty() and timestamp - qu.front().first >= 10) {
            entries.erase(qu.front().second);
            qu.pop();
        }
        if(entries.find(message) != entries.end()) {
            return false;
        } else {
            entries.insert(message);
            qu.push({timestamp, message});
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
