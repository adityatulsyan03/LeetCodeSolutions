class Solution {
public:
    int maxDepth(string s) {
        int mx=0,o=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                o++;
            else if(s[i]==')'){
                mx= max(mx,o);
                o--;
            }               
        }
        return mx;
    }
};