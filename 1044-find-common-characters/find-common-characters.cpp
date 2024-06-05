class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int> cnt;
        vector<string> ans;
        for(char i:words[0]){
            cnt[i]++;
        }
        for(int i=1;i<words.size();i++){
            vector<int> temp(26,0);
            for(char j:words[i])
                temp[j-'a']++;
            for(auto [j,k]:cnt){
                if(temp[j-'a']<k)
                    cnt[j]=temp[j-'a'];
            }
        }
        for(auto [i,j]:cnt)
            while(j--)  ans.push_back(string(1,i));
        return ans;
    }
};