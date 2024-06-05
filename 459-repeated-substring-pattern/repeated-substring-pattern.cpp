class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string temp = s;
        s+=s;
        s[0]=' ';
        s[s.size()-1]=' ';
        if(s.find(temp)!=string::npos)  return true;
        return false;
    }
};