class Solution {
private:
    bool helper(string s,int l,int r){
        while(l<=r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else{
                return false;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<=r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else{
                break;
            }
        }
        if(l!=r){
            return helper(s,l+1,r) || helper(s,l,r-1);
        }
        return true;
    }
};