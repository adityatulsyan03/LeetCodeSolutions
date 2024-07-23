class Solution {
private:
    void helper(vector<string>& total,string temp,int i,int n,string use){
        if(i==n)
            total.push_back(temp);
        else{
            for(char j:use){
                string t=temp;
                temp+=j;
                helper(total,temp,i+1,n,use);
                temp=t;        
            }
        }
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector<string> total;
        string temp="",use="01";
        int n=nums[0].size();
        helper(total,temp,0,n,use);
        if(total.size()!=nums.size()){
            unordered_map<string,int> cnt;
            for(string i:nums)
                cnt[i]++;
            for(string i:total)
                if(!cnt[i]) return i;
        }
        return "";
    }
};