class Solution {
public:
    string makeFancyString(string s) {
        string a="";
        a+=s[0];
        for(int i=1;i<s.size();){
            if(s[i]==s[i-1]&&s[i]==s[i+1])
                i++;
            else
                a+=s[i++];
        }
        return a;
    }
};