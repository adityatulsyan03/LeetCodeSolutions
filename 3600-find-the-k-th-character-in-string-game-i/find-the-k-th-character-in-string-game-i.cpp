class Solution {
private:
    char solve(int k,string s){
        if(s.size()>=k){
            return s[k-1];
        }
        string t=s;
        for(char& c:t){
            c=(c-'a'+1)%26+'a';
        }
        return solve(k,s+t);
    }
public:
    char kthCharacter(int k) {
        string s="a";
        return solve(k,s);
    }
};