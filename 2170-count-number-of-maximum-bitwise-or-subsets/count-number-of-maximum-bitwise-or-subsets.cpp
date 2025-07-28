class Solution {
int cnt=0;
private:
    void generateSubsets(int mx, vector<int>& nums,int index, vector<int>& curr){
        if (index == nums.size()) {
            int a=0;
            for(auto i:curr)
                a = a|i;
            if(mx==a)
                cnt++;
            return;
        }
        generateSubsets(mx, nums, index+1, curr);
        curr.push_back(nums[index]);
        generateSubsets(mx, nums, index+1, curr);
        curr.pop_back();
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx=0;
        for(auto i:nums)
            mx = mx|i;
        vector<int> curr;
        generateSubsets(mx, nums, 0, curr);
        return cnt;
    }
};