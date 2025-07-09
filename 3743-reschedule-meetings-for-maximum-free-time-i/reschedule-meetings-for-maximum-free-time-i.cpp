class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> ans;
        ans.push_back(startTime[0] - 0);
        for (int i = 1; i < n; i++) {
            ans.push_back(startTime[i] - endTime[i - 1]);
        }
        ans.push_back(eventTime - endTime[n - 1]);
        
        int size = k+1;
        if(ans.size() < size){
            size = ans.size();
        }
        
        long long currentSum = 0;
        for (int i = 0; i < size; i++) {
            currentSum += ans[i];
        }
        long long a = currentSum;
        
        for (int i = size; i < ans.size(); i++) {
            currentSum += ans[i] - ans[i - size];
            a = max(a, currentSum);
        }
        
        return a;
    }
};
