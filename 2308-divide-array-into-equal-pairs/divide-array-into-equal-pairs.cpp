class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num:nums)
            freq[num]++;
        for(auto [i,j]:freq)
            if(j%2==1)  return false;
        return true;
    }
};