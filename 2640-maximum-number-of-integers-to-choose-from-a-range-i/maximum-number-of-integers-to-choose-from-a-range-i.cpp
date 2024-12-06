class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans=0,i=0,cnt=1;
        sort(banned.begin(),banned.end());
        for(int i:banned)   cout<<i<<" ";
        cout<<endl<<endl;
        while(maxSum>=0 && cnt<=n){
            if(i<banned.size() && cnt==banned[i]){
                i++;
                while(i<banned.size() && cnt==banned[i]){
                    i++;
                }
            }
            else{
                if(cnt<=maxSum){
                    cout<<cnt<<endl;
                    ans++;
                }
                maxSum-=cnt;
            }
            cnt++;
        }
        return ans;
    }
};