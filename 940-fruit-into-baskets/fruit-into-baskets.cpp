class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        if(fruits.size()<=2)
            return fruits.size();
        int ans=0;
        int i=0,j=0;
        unordered_map<int,int> cnt;
        while(i<n && j<n && i<=j){
            cnt[fruits[j]]++;
            j++;
            while(cnt.size()>2){
                cnt[fruits[i]]--;
                if (cnt[fruits[i]] == 0) {
                    cnt.erase(fruits[i]);
                }
                i++;
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};