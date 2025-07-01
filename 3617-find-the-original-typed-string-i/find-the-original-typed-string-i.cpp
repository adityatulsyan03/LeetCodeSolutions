class Solution {
public:
    int possibleStringCount(string word) {
        vector<int> cnt;
        char curr=word[0];
        int val=0;
        for(int i=0;i<word.size();i++){
            if(word[i]==curr)   val++;
            else{
                cnt.push_back(val);
                curr=word[i];
                val=1;
            }
        }
        cnt.push_back(val);
        int ans=1;
        for(int i:cnt)  ans+=i>1?i-1:0;
        return ans;
    }
};