class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())   return false;
        if(s==goal) return true;
        goal+=goal;
        for(int i=0;i<s.size();i++){
            string sub=goal.substr(i,s.size());
            if(sub==s)  return true;
        }
        return false;
    }
};