class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start_ptr,end_ptr;
        for(int i=0;i<intervals.size();i++){
            start_ptr.push_back(intervals[i][0]);
            end_ptr.push_back(intervals[i][1]);
        }
        sort(start_ptr.begin(),start_ptr.end());
        sort(end_ptr.begin(),end_ptr.end());
        int ans=0,end=0;
        for(int start:start_ptr){
            if(start>end_ptr[end]){
                end++;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};