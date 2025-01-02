class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefixSum(words.size()+1,0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for(int i=0;i<words.size();i++){
            if(
                vowels.count(words[i][0]) && 
                vowels.count(words[i][words[i].size()-1])
            ){
                prefixSum[i+1]=prefixSum[i]+1;
            }
            else{
                prefixSum[i+1]=prefixSum[i];
            }
        }
        vector<int> ans;
        for (auto& query:queries) {
            int f=query[0],s=query[1];
            ans.push_back(prefixSum[s+1]-prefixSum[f]);
        }
        return ans;
    }
};