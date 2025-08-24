class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> cnt;
        int c=0;
        for(int i:nums){
            c+=i;
            if(i==0){
                cnt.push_back(c);
                c=0;
            }
        }
        if(c!=0)    cnt.push_back(c);
        if(cnt.size()==1){
            return cnt[0]==0?0:cnt[0]-1;
        }
        int ans=0;
        for(int i=0;i<cnt.size()-1;i++){
            ans=max(ans,cnt[i]+cnt[i+1]);
        }
        return ans;
    }
};