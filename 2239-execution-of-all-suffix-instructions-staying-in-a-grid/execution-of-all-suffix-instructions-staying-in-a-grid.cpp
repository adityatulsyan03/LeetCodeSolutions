class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m=s.size();
        vector<int> result(m,0);
        for(int i=0;i<m;i++){
            int ans=0,s1=startPos[0],s2=startPos[1];
            for(int j=i;j<m;j++){
                if(s[j]=='R'){
                    s2++;
                }
                else if(s[j]=='L'){
                    s2--;
                }
                else if(s[j]=='U'){
                    s1--;
                }
                else{
                    s1++;
                }
                if(s1<0 || s1>=n || s2<0 || s2>=n){
                    result[i]=ans;
                    break;
                }
                ans++;
            }
            result[i]=ans;
        }
        return result;
    }
};