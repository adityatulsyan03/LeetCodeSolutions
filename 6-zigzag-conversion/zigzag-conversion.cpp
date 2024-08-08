class Solution {
public:
    string convert(string s, int numRows) {
        string ans="";
        if(numRows==1){
            return s;
        }
        int c=(numRows*2)-2;
        unordered_map<int,string> mp;
        for(int i=0;i<numRows;i++){
            mp[i]="";
        }
        int j=0;
        bool f=true;
        for(int i=0;i<s.size();i++){
            mp[j]+=s[i];
            if(j==numRows-1){
                f=false;
            }
            else if(j==0){
                f=true;
            }
            if(f){
                j++;
            }
            else{
                j--;
            }
        }
        for(int i=0;i<numRows;i++)
            ans+=mp[i];
        return ans;
    }
};