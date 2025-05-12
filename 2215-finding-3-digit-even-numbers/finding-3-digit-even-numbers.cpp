class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10,0); 
        int cnt=0;
        for(int x: digits){
            freq[x]++;
            cnt+=(x&1)==0;
        }
        if (cnt==0) return {};
        vector<int> ans;
        for(int x=100; x<=999; x+=2){
            auto freq0=freq;
            int x0=x%10, x1=(x/10)%10, x2=x/100;
            if (freq0[x0]--<=0) continue;
            if (freq0[x1]--<=0) continue;
            if (freq0[x2]--<=0) continue;
            ans.push_back(x);
        }
        return ans;
    }
};