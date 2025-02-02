class Solution {
public:
    int maxDifference(string s) {
        int e=s.size(),o=0;
        vector<int> cnt(26,0);
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(cnt[i]%2==1){
                o=max(o,cnt[i]);
            }
            if(cnt[i]!=0 && cnt[i]%2==0){
                if(e>cnt[i]){
                    e=cnt[i];
                }
            }
        }
        return o-e;
    }
};