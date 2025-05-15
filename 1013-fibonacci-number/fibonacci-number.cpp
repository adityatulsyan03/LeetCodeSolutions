class Solution {
public:
    int fib(int n) {
        vector<int> mem(n+1,0);
        if (n<=1) return n;
        mem[1]=1;
        for(int i=2;i<=n;i++){
            mem[i]=mem[i-1]+mem[i-2];
        }
        return mem[n];
    }
};