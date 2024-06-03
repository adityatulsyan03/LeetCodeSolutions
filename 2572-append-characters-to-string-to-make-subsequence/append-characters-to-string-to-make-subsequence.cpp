class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans=0,j=0,i=0;
        for(;j<s.size() && i<t.size();){
            if(s[j]==t[i])
                i++;
            j++;
        }
        ans += t.size()-i;
        return ans;
    }
};