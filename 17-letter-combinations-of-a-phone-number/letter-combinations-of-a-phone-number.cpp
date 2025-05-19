class Solution {
private:
    void helper(unordered_map<char,string>& cnt,vector<string>& ans,string a,string digits,int i){
        if(digits.size()==a.size()){
            ans.push_back(a);
            return;
        }
        for(char j:cnt[digits[i]]){
            string b=a;
            b+=j;
            helper(cnt,ans,b,digits,i+1);

        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> cnt;
        cnt['2']="abc";
        cnt['3']="def";
        cnt['4']="ghi";
        cnt['5']="jkl";
        cnt['6']="mno";
        cnt['7']="pqrs";
        cnt['8']="tuv";
        cnt['9']="wxyz";
        vector<string> ans;
        if(digits.size()==0){
            return ans;
        }
        string a="";
        helper(cnt,ans,a,digits,0);
        return ans;
    }
};