class Solution {
private:
unordered_map<char,char> par;
    void setParent(char child,char parent){
        if(par[child]==parent)
            return;
        else{
            char new_child=par[child];
            par[child]=parent;
            if(new_child<parent)    setParent(parent,new_child);
            else    setParent(new_child,parent);
        }
    }
    char findParent(char child){
        if(par[child]==child)
            return child;
        else
            return findParent(par[child]);
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i=0;i<26;i++)   par['a'+i]='a'+i;
        for(int i=0;i<s1.size();i++){
            if(s1[i]>s2[i]) setParent(s1[i],s2[i]);
            else    setParent(s2[i],s1[i]);
        }
        for(int i=0;i<26;i++){
            char a = 'a'+i;
            cout<<a<<" "<<par[a]<<endl;
        }
        for(int i=0;i<baseStr.size();i++)   baseStr[i]=findParent(baseStr[i]);
        return baseStr;
    }
};