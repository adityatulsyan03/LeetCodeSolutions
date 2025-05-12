class Solution {
private:
    void solve(vector<int>& digits, unordered_set<int>& s, int size, int num, vector<bool>& used) {
        if (size == 3) {
            s.insert(num);
            return;
        }

        for (int i = 0; i < digits.size(); i++) {
            if (used[i] || (size==2 && digits[i]==0)) continue;

            used[i] = true;
            int t = num + digits[i] * pow(10, size);
            solve(digits, s, size + 1, t, used);
            used[i] = false;
        }
    }

public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> s;

        for (int i = 0; i < digits.size(); i++) {
            if(digits[i]%2) continue;
            vector<bool> used(digits.size(), false);
            used[i] = true;
            solve(digits, s, 1, digits[i], used);
        }
        for(int i:s){
            cout<<i<<" ";
        }
        return s.size();
    }
};