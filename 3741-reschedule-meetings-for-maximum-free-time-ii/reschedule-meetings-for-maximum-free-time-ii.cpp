class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int m = n + 1;
        vector<int> gaps;
        gaps.push_back(startTime[0]);
        int ans = startTime[0];
        for (int i = 1; i < n; i++) {
            gaps.push_back(startTime[i] - endTime[i - 1]);
            ans=max(ans,gaps[i]);
        }
        gaps.push_back(eventTime - endTime[n - 1]);
        ans=max(ans,gaps[n]);
        
        vector<int> pref(m), suf(m);
        pref[0] = gaps[0];
        for (int i = 1; i < m; i++) {
            pref[i] = max(pref[i - 1], gaps[i]);
        }
        suf[m - 1] = gaps[m - 1];
        for (int i = m - 2; i >= 0; i--) {
            suf[i] = max(suf[i + 1], gaps[i]);
        }
        
        for (int i = 0; i < n; i++) {
            int d = endTime[i] - startTime[i];
            int new_gap = 0;
            if(n == 1) {
                new_gap = eventTime;
            } else if(i == 0) {
                new_gap = startTime[1] - 0;
            } else if(i == n - 1) {
                new_gap = eventTime - endTime[n - 2];
            } else {
                new_gap = startTime[i + 1] - endTime[i - 1];
            }
            
            int outside_gap = 0;
            if(i - 1 >= 0)
                outside_gap = max(outside_gap, pref[i - 1]);
            if(i + 2 < m)
                outside_gap = max(outside_gap, suf[i + 2]);
            
            int temp = 0;
            if(outside_gap >= d) {
                temp = new_gap;
            } else {
                temp = new_gap - d;
            }
            ans = max(ans, temp);
        }
        
        return ans;
    }
};