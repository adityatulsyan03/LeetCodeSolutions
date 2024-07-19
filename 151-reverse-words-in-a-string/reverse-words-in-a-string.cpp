class Solution {
public:
    string reverseWords(string s) {
        string temp="",ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(temp!=""){
                    ans=' '+temp+ans;
                    temp="";
                }
            }
            else{
                temp+=s[i];
            }
        }
        if(temp!="")
            ans=' '+temp+ans;
        if(!ans.empty() && ans[0]==' ')
            ans=ans.substr(1);
        return ans;
    }
};