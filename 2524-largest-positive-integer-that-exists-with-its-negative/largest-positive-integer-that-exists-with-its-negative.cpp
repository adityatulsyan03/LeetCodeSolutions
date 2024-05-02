class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(auto i:nums)
            cout<<i<<" ";
        cout<<endl;
        int i=0,j=nums.size()-1;
        while(i<j){
            if(abs(nums[i])==abs(nums[j])){
                break;
            }
            if(abs(nums[i])>abs(nums[j])){
                i++;
            }
            else{
                j--;
            }
        }
        cout<<i<<" "<<j<<endl;
        return (nums[i]==(-1*nums[j]))?nums[j]:-1;
    }
};