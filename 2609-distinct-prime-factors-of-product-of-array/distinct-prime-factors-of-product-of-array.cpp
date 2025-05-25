class Solution {
int ans=0;
private:
    void helper(int num,vector<bool>& val){
        if (val[num]) return;
        for (int i = 2; i <= num; ++i) {
            if (num % i != 0) continue;
            if (!val[i]) {
                ans++;
                val[i] = true;
            }
            while (num % i == 0) {
                num /= i;
            }
            if (num == 1) break;
        }
    }
public:
    int distinctPrimeFactors(vector<int>& nums) {
        vector<bool> val(1001, false);
        for (int i : nums) {
            helper(i, val);
        }
        return ans;
    }
};