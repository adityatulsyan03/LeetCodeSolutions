bool customComparator(vector<int>& a, vector<int>& b) {
    return a[0] < b[0]; // Max-heap
}
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> v(n, vector<int>(m, INT_MIN));
        priority_queue<vector<int>, vector<vector<int>>, decltype(&customComparator)> pq(customComparator);
        if (grid[0][0]) health--;
        if (health <= 0) return false;

        v[0][0] = health;
        pq.push({health, 0, 0});

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!pq.empty()) {
            vector<int> top = pq.top();
            int h = top[0], i = top[1], j = top[2];
            pq.pop();
            for (auto [di, dj] : directions) {
                int ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                int newHealth = grid[ni][nj] ? h - 1 : h;
                if (newHealth > v[ni][nj]) {
                    v[ni][nj] = newHealth;
                    if (newHealth > 0) pq.push({newHealth, ni, nj});
                }
            }
        }
        return v[n - 1][m - 1] > 0;
    }
};
