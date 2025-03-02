class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> sum;
        for(auto i:nums1){
            sum[i[0]]+=i[1];
        }
        for(auto i:nums2){
            sum[i[0]]+=i[1];
        }
        vector<vector<int>> ans;
        for(auto [i,j]:sum){
            ans.push_back({i,j});
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};