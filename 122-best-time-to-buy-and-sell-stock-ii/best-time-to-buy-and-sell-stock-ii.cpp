class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=prices[0],ans=0;
        for(int i=1;i<prices.size();i++){
            mn=min(mn,prices[i]);
            if(prices[i]-mn>0){
                ans+=prices[i]-mn;
                mn=prices[i];
            }
        }
        return ans;
    }
};