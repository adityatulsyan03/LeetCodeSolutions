class Solution {
private:
    int helper(vector<int> nums,int n){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(abs(nums[i]-nums[j])>n){
                    continue;
                }
                else{
                    ans++;
                }
            }
        }
        return ans;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int s=0,e=nums[nums.size()-1]-nums[0];
        while(s<e){
            int mid = (s+e)/2;
            int cnt=helper(nums,mid);
            if(cnt>=k){
                e=mid;
            }
            else{
                s=mid+1;
            }
        }
        return s;
    }
};