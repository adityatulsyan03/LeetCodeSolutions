class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.rbegin(),tasks.rend());
        int ans=0;
        int n=tasks.size();
        for(int i=0;i<n;i++){
            ans=max(ans,processorTime[i/4]+tasks[i]);
        }
        return ans;
    }
};