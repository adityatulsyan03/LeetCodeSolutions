class Solution {
private:
    void helper(int n,unordered_set<string>& ans,string temp){
        if(temp.size()==n*2){
            ans.insert(temp);
        }
        else{
            string a="()";
            for(int i=0;i<=temp.size();i++){
                string t=temp;
                t.insert(i,a);
                helper(n,ans,t);
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> a;
        string temp="";
        helper(n,a,temp);
        vector<string> ans(a.begin(),a.end());
        return ans;
    }
};