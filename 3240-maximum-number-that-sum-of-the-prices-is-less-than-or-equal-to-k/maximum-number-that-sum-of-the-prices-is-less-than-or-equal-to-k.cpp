class Solution {
private:
    int countBits(long long n){
        int ans=0;
        while(n>0){
            ans++;
            n=n>>1;
        }
        return ans;
    }
    long long powerOf2(int i) {
        return 1LL << i;
    }
    long long calc(long long n,int x){
        int i=countBits(n);
        long long ans=0;
        n++;
        while(i){
            if(i%x==0){
                ans+=(n / powerOf2(i)) * (powerOf2(i - 1)) + max(0LL, (n % powerOf2(i)) - powerOf2(i - 1));
            }

            i--;
        }
        return ans;
    }
public:
    long long findMaximumNumber(long long k, int x) {
        long long low = 1;
        long long high = 1e15;
        while(low <= high) {
            long long mid = (high - low) / 2 + low;
            long long res = calc(mid, x);            
            if(res <= k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};