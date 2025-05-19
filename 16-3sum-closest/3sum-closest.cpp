class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            int s=i+1,e=nums.size()-1;
            while(s<e){
                int c=curr+nums[s]+nums[e];
                if(abs(ans-target)>abs(c-target)){
                    ans=c;
                }
                if(c<target){
                    s++;
                }
                else if(c>target){
                    e--;
                }else{
                    return c;
                }
            }
        }
        return ans;
    }
};