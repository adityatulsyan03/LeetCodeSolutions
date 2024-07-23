class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> cnt(300,0);
        for(int i:nums){
            cnt[i+100]++;
        }
        map<int,vector<int>> mp;
        for(int i=0;i<300;i++){
            if(cnt[i]!=0)
                mp[cnt[i]].push_back(i-100);
        }
        vector<int> ans;
        for(auto [i,j]:mp){
            reverse(j.begin(),j.end());
            for(int k:j){
                int a=i;
                while(a--)
                    ans.push_back(k);
            }
        }
        return ans;
    }
};