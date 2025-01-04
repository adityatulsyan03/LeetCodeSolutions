class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int ans=0;
        unordered_set<char> vowels={'a','e','i','o','u'};
        int n=s.size();
        for(int i=0;i<n;i++){
            int v=0,c=0;
            for(int j=i;j<n;j++){
                if(vowels.count(s[j])){
                    v++;
                }else{
                    c++;
                }
                if(c==v && (c*v)%k==0)  ans++;
            }
        }
        return ans;
    }
};