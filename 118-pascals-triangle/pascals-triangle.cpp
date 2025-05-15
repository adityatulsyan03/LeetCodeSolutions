class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        numRows--;
        vector<int> prev={1};
        while(numRows--){
            vector<int> curr(prev.size()+1,1);
            for(int i=1;i<(curr.size()+1)/2;i++){
                curr[i]=prev[i]+prev[i-1];
                curr[curr.size()-i-1]=curr[i];
            }
            ans.push_back(curr);
            prev=curr;
        }
        return ans;
    }
};