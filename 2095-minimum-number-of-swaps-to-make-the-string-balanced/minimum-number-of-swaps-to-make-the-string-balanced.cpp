class Solution {
public:
    int minSwaps(string s) {
        int o=s.size()-1,c=0;
        while(s[o]!='[')    o--;
        int cnt=0,ans=0;
        while(c<=o){
            if(s[c]=='[')   cnt--;
            if(s[c]==']')   cnt++;
            if(cnt>0){
                swap(s[c],s[o]);
                o--;
                ans++;
                cnt-=2;
            }
            c++;
        }
        return ans;
    }
};