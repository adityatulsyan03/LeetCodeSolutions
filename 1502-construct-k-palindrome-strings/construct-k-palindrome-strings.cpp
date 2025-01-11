class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        int cnt=0;
        for(int i:freq){
            if(i%2==1)  cnt++;
        }
        return cnt<=k && s.size()>=k;
    }
};