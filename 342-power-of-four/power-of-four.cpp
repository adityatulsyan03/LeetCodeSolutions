class Solution {
private:
    bool helper(int n){
        if(n==0 || n==2)    return false;
        if(n==1)    return true;
        if(((n&1)==1 && n!=1) || (n&2)==2){
            return false;
        }
        return helper(n>>2);
    };
public:
    bool isPowerOfFour(int n) {
        return helper(n);
    }
};