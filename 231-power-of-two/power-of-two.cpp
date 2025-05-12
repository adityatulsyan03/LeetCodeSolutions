class Solution {
private:
    bool solve(int n){
        if(n==1){
            return true;
        }
        if(n<=0 || n%2!=0){
            return false;
        }
        return solve(n>>1);
    }
public:
    bool isPowerOfTwo(int n) {
        return solve(n);
    }
};