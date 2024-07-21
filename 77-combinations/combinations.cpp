class Solution {
private:
    void helper(vector<vector<int>>& ans,vector<int> temp,int i,int n,int k){
        if(temp.size()==k)
            ans.push_back(temp);
        else{
            for(int j=i;j<=n;j++){
                temp.push_back(j);
                helper(ans,temp,j+1,n,k);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans,temp,1,n,k);
        return ans;
    }
};