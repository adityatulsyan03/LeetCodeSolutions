class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26,0);
        int total=0;
        for(string s:words2){
            vector<int> temp(26,0);
            for(char c:s){
                temp[c-'a']++;
            }
            for(int i=0;i<26;i++){
                freq[i]=max(freq[i],temp[i]);
            }
        }
        for(int i:freq){
            if(i>0) total++;
        }
        vector<string> ans;
        for(string s:words1){
            vector<int> temp=freq;
            int t=total;
            for(char c:s){
                temp[c-'a']--;
                if(temp[c-'a']==0)  t--;
            }
            if(t==0){
                ans.push_back(s);
            }
        }
        return ans;
    }
};