class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        map<int,int> mp;
        int ans=0;
        int mx=0;
        for(int num:candidates){
            for(int i=0;i<=30;i++){
                if((1<<i & num) > 0)
                    mp[i]++, mx= max(mx,mp[i]);
            }
        }
        return mx;
    }
};