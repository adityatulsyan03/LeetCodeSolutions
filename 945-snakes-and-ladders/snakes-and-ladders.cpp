class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        unordered_map<int, int> goTo;

        bool leftToRight = true;
        int num = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (leftToRight) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] != -1)
                        goTo[num] = board[i][j];
                    num++;
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    if (board[i][j] != -1)
                        goTo[num] = board[i][j];
                    num++;
                }
            }
            leftToRight = !leftToRight;
        }

        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front(); q.pop();
            for (int i = 1; i <= 6; i++) {
                int next = curr + i;
                if (next > n * n) break;
                if (goTo.count(next)) next = goTo[next];
                if (next == n * n) return moves + 1;
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }

        return -1;
    }
};