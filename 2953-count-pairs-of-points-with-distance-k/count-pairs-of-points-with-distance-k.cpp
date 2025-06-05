class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        unordered_map<long long, int> mp;
        int cnt = 0;

        for (auto& i : coordinates) {
            int x1 = i[0], y1 = i[1];

            for (int x = 0; x <= k; ++x) {
                int y = k - x;
                int x2 = x ^ x1;
                int y2 = y ^ y1;
                long long key = ((long long)x2 << 20) | y2;
                cnt += mp[key];
            }

            long long key = ((long long)x1 << 20) | y1;
            mp[key]++;
        }

        return cnt;
    }
};