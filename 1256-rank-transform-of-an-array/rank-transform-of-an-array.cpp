class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0)
            return arr;
        if(arr.size()==1){
            vector<int> ans;
            ans.push_back(1);
            return ans;
        }
        vector<int> ans=arr;
        int n=arr.size(),j=2;
        sort(ans.begin(),ans.end());
        unordered_map<int,int> rank;
        rank[ans[0]]=1;
        for(int i=1;i<n;i++){
            if(ans[i]!=ans[i-1]){
                rank[ans[i]]=j;
                j++;
            }
        }
        for(int i=0;i<n;i++){
            ans[i]=rank[arr[i]];
        }
        return ans;
    }
};