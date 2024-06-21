class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0,n=grumpy.size();
        for(int i=0;i<n;i++){
            ans += grumpy[i]==1?0:customers[i];
            if(i<minutes && grumpy[i])   ans += customers[i];
        }
        int mx=ans,i=minutes;
        cout<<mx<<endl;
        while(i<n){
            if(grumpy[i])
                ans+=customers[i];
            if(grumpy[i-minutes])
                ans-=customers[i-minutes];
            mx=max(ans,mx);
            i++;
        }
        return mx;
    }
};