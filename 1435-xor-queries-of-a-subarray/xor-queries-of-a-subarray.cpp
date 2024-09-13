class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix;
        int sum=0;
        for(int i:arr){
            sum^=i;
            prefix.push_back(sum);
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==0)
                ans.push_back(prefix[queries[i][1]]);
            else
                ans.push_back(prefix[queries[i][1]]^prefix[queries[i][0]-1]);
        }
        return ans;
    }
};