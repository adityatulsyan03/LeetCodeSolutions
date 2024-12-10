class Solution {
private:
    void fill(vector<int>& mem,int n){
        if(mem[n]!=0){
            return;
        }
        if(n-1>0)   fill(mem,n-1);
        if(n-2>0)   fill(mem,n-2);
        mem[n]=mem[n-1]+mem[n-2];
    }
public:
    int fib(int n) {
        vector<int> mem(n+1,0);
        if (n >= 1) mem[1] = 1;
        if (n == 0) return 0;
        fill(mem,n);
        return mem[n];
    }
};