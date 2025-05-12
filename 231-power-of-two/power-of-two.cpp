class Solution {
private:
    bool solve(int n){
        if(n==0)    return false;
        if(n==1){
            return true;
        }
        if((n&1)==1 && n!=1){
            return false;
        }
        return solve(n>>1);
    }
public:
    bool isPowerOfTwo(int n) {
        return solve(n);
    }
};