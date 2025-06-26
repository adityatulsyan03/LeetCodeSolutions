class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans=0,val=0,pos=0,i=s.size()-1;
        for(;i>=0;i--){
            if(s[i]=='0'){
                ans++;
                pos++;
            }
            else if(pos < 31 && val + (1 << pos) <= k){
                val += (1 << pos);
                ans++;
                pos++;
            }
        }
        return ans;
    }
};