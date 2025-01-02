class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefixSum(words.size()+1,0);
        string vowel="aeiou";
        for(int i=0;i<words.size();i++){
            bool first = vowel.find(words[i][0])!=string::npos;
            if(
                vowel.find(words[i][0])!=string::npos && 
                vowel.find(words[i][words[i].size()-1])!=string::npos
            ){
                prefixSum[i+1]=prefixSum[i]+1;
            }
            else{
                prefixSum[i+1]=prefixSum[i];
            }
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int f=queries[i][0],s=queries[i][1];
            ans.push_back(prefixSum[s+1]-prefixSum[f]);
        }
        return ans;
    }
};