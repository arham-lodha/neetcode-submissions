class MinStack {
public:
    vector<pair<int, int>> arr; //actual val, min so far

    MinStack() {
        arr = {{0, INT_MAX}};    
    }
    
    void push(int val) {
        arr.push_back({val, min(arr.back().second, val)});
    }
    
    void pop() {
        if(arr.size() > 1) arr.pop_back();
    }
    
    int top() {
        return arr.back().first;
    }
    
    int getMin() {
        return arr.back().second;
    }
};
