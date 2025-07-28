class Solution {
int cnt=0;
private:
    void generateSubsets(int mx, vector<int>& nums,int index, int curr){
        if (index == nums.size()) {
            if(mx==curr)
                cnt++;
            return;
        }
        generateSubsets(mx, nums, index+1, curr);
        generateSubsets(mx, nums, index+1, curr|nums[index]);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx=0;
        for(auto i:nums)
            mx = mx|i;
        int curr=0;
        generateSubsets(mx, nums, 0, curr);
        return cnt;
    }
};