class Solution {
public:
    int specialArray(vector<int>& nums) {
        unordered_map<int,int> cnt;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mx=nums[n-1];
        for(int i=0;i<=mx;i++){
            for(int j=0;j<n;j++){
                if(i<=nums[j])
                    cnt[i]++;
            }
        }
        for(auto [i,j]:cnt)
            if(j==i)
                return i;
        return -1;
    }
};