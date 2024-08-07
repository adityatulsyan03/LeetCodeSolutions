class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        int l=0,r=0,mx=0;
        while(l<n && r<n && l<=r){
            mp[s[r]]++;
            if(mp[s[r]]==1)
                mx=max(mx,r-l+1);
            if(mp[s[r]]==2){
                while(r<n && l<n && mp[s[r]]==2){
                    mp[s[l]]--;   
                    l++;
                }
            }
            r++;
        }
        return mx;
    }
};