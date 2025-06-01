class Solution {
int ans=0;
private:
    void helper(int child,int left,int limit){
        if(left==0 && child==4){
            ans++;
            return;
        }
        if(child>4){
            return;
        }
        for(int i=0;i<=limit;i++){
            if(left<i)  break;
            helper(child+1,left-i,limit);
        }
    }
public:
    int distributeCandies(int n, int limit) {
        helper(1,n,limit);
        return ans;
    }
};