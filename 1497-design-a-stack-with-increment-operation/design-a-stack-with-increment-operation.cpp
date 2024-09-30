class CustomStack {
vector<int> a;
int size=0;
public:
    CustomStack(int maxSize) {
        size=maxSize;
    }
    
    void push(int x) {
        if(a.size()<size)
            a.push_back(x);
    }
    
    int pop() {
        int val=-1;
        if(a.size()>0)  val=a[a.size()-1],  a.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
        int t=k;
        if(t>a.size())
            t=a.size();
        for(int i=0;i<t;i++){
            a[i]+=val;
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