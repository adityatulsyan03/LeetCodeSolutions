class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }

        while(k--){
            auto p=pq.top();
            pq.pop();
            pq.push({p.first*multiplier,p.second});
        }

        while(!pq.empty()){
            auto p=pq.top();
            nums[p.second]=p.first;
            pq.pop();
        }

        return nums;
    }
};