class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<int> cnt(26,0);
        for(char c:s){
            cnt[c-'a']++;
        }
        deque<int> dq;
        for(int i=0;i<26;i++){
            dq.push_back(cnt[i]);
        }
        while(t--){
            int back = dq.back();
            dq.pop_back();
            if(back==0){
                dq.push_front(0);
            }
            else{
                int front = dq.front();
                dq.pop_front();
                dq.push_front((front+back)%MOD);
                dq.push_front(back);
            }
        }
        int ans=0;
        for(int i:dq){
            ans=(ans+i)%MOD;
        }
        return ans;
    }
};