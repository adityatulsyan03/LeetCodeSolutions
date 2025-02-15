class Solution {
private:
    bool ispossible(int n,int sq,int sum){
        int temp=0;
        int idx=0;
        while(sq>0){
            int last=sq%10;
            sq/=10;
            temp = temp + last*pow(10,idx);
            idx++;
            if(sq+sum+temp==n){
                return true;
            }else{
                if (ispossible(n, sq, sum + temp)) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            if(ispossible(i,i*i,0)){
                ans+=(i*i);
                cout<<i<<endl;
            }
        }
        return ans;
    }
};