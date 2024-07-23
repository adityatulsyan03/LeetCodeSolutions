class Solution {
private:
    void helper(int n,vector<string>& ans,string curr,char last,string v,int s){
        if(s==n){
            ans.push_back(curr);
        }
        else{
            for(char i:v){
                if(last=='\0' || i!=last){
                    string c=curr;
                    curr+=i;
                    helper(n,ans,curr,i,v,s+1);
                    curr=c;            
                }
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string> ans;
        string curr="",v="abc";
        helper(n,ans,curr,'\0',v,0);
        if(k-1<ans.size())
            return ans[k-1];
        else
            return "";
    }
};