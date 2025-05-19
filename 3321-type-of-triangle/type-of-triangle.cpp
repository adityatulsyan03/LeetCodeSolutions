class Solution {
public:
    string triangleType(vector<int>& nums) {
        set a(nums.begin(),nums.end());
        if(a.size()==1){
            return "equilateral";
        }
        if(a.size()==2){
            if((nums[0]==nums[1] && (2*nums[0])>nums[2]) || (nums[1]==nums[2] && (2*nums[1])>nums[0]) || (nums[0]==nums[2] && (2*nums[0])>nums[1]))
                return "isosceles";
            else
                return "none";
        }
        if( (nums[0]+nums[1] > nums[2]) && (nums[1]+nums[2] > nums[0]) && (nums[2]+nums[0] > nums[1])){
            return"scalene";
        }
        return "none";
    }
};