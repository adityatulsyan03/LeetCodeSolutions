class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]!=nums[i])
                nums[j++]=nums[i+1];
        }
        return j;
    }
};