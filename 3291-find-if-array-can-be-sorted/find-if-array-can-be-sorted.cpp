class Solution {
private:
    int countBits(int number) {
        int count = 0;
        while (number > 0) {
            if (number & 1)
                count++;
            number >>= 1;
        }
        return count;
    }

public:
    bool canSortArray(vector<int>& nums) {
        map<int, int> a;
        for (int i = 0; i < nums.size(); i++) {
            a[i]=countBits(nums[i]);
        }

        vector<int> b=nums;
        sort(b.begin(),b.end());
        
        map<int,pair<int,int>> index;
        for(int i=0;i<b.size();i++){
            index[nums[i]].first=i;
            index[b[i]].second=i;
        }
        for(auto i:index){
            int mn=i.second.first;
            if(mn>i.second.second)
                mn=i.second.second;
            for(int j=mn;j<max(i.second.first,i.second.second);j++){
                if(a[j]!=countBits(i.first))
                    return false;
            }
        }
        
        return true;
    }
};
