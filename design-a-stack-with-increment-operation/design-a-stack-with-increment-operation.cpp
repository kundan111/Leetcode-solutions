class CustomStack {
private:
    vector<int>st;
    int top;
    int maxSz;
public:
    CustomStack(int maxSize) {
        st.resize(maxSize);
        top = -1;
        maxSz = maxSize;
    }
    
    void push(int x) {
        if(top < maxSz-1)
        {
            top++;
            st[top] = x;
        }
    }
    
    int pop() {
        if(top == -1)
        {
            return -1;
        }
        
        int retVal = st[top];
        top--;
        
        return retVal;
    }
    
    void increment(int k, int val) {
        if(top == -1)
        {
            return;
        }
        
        int count = 0;
        while(count < k && count <= top && count < maxSz)
        {
            st[count] += val;
            count++;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */