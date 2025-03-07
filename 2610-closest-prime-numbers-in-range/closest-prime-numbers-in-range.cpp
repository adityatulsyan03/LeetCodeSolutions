class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isprime(right+1,true);
        vector<int> prime;
        isprime[0]=false;
        isprime[1]=false;
        for(int i=2;i*i<=right;i++){
            if(isprime[i]==false){
                continue;
            }
            for(int j=i*i;j<=right;j+=i){
                isprime[j]=false;
            }
        }
        for(int i=0;i<isprime.size();i++){
            if(isprime[i] && i>=left && i<=right)
                prime.push_back(i);
        }
        if(prime.size()<2){
            return {-1,-1};
        }
        int f=-1,s=-1,diff=INT_MAX;
        for(int i=0;i<prime.size()-1;i++){
            if(diff>prime[i+1]-prime[i]){
                diff=prime[i+1]-prime[i];
                f=prime[i];
                s=prime[i+1];
            }
        }
        return {f,s};
    }
};