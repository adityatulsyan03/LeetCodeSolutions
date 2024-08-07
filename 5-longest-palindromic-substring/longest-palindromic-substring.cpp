class Solution {
private:
    bool check(int l,int r,string s){
        while(l>=0 && r<s.size() && l<=r){
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string longest="";
        for(int l=0;l<n;l++){
            int t=0;
            for(int r=l;r<n;r++){
                t=t^s[r];
                if( (r-l+1) % 2 == 1){
                    t=t^s[(r+l)/2];
                }
                if (t==0 && check(l, r, s)) {
                    if (r - l + 1 > longest.size()) {
                        longest = s.substr(l, r - l + 1);
                    }
                }
                if( (r-l+1) % 2 == 1){
                    t=t^s[(r+l)/2];
                }
            }
        }
        return longest;
    }
};