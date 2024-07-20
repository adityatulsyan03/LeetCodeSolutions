class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string t="",ans="";
        for(int i=0;i<path.size();i++){
            if(path[i]!='/')
                t+=path[i];
            else{
                if(t!="")   v.push_back(t);
                t="";
            }
            if(i==path.size()-1 && t!="")   v.push_back(t);
        }
        int c=0;
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]=="..")
                c++;
            else if(v[i]==".")
                continue;
            else{
                if(c>0){
                    c--;
                    continue;
                }
                else{
                    ans='/'+v[i]+ans;
                }
            }
        }
        if(ans=="")
            ans='/';
        return ans;
    }
};