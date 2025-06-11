class Solution {
private:
    int getStatus(int a,int b){
        return ((a&1) << 1) | (b&1);
    }
public:
    int maxDifference(string s, int k) {
        int ans=INT_MIN,n=s.size();
        for(char a='0';a<='4';a++){
            for(char b='0';b<='4';b++){
                if(a==b)    continue;

                int l=-1;
                int cnt_a=0,cnt_b=0;
                int prev_a=0,prev_b=0;

                vector<int> best(4,INT_MAX);
                for(int r=0;r<n;r++){
                    cnt_a+=(s[r]==a);
                    cnt_b+=(s[r]==b);
                    while(r-l>=k && cnt_b-prev_b>=2){
                        
                        int leftStatus = getStatus(prev_a,prev_b);

                        best[leftStatus] = min(best[leftStatus],prev_a-prev_b);
                        l++;

                        prev_a+=(s[l]==a);
                        prev_b+=(s[l]==b);
                    }
                    int right_status = getStatus(cnt_a,cnt_b);
                    if(best[right_status^0b10] != INT_MAX){
                        ans=max(ans,cnt_a-cnt_b-best[right_status^0b10]);
                    }
                }
            }
        }
        return ans;
    }
};