class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        unordered_map<int,int> mp;
        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                mp[hFences[j]-hFences[i]]++;
            }
        }
        int maxi=-1;
        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                if(mp[vFences[j]-vFences[i]]){
                    maxi=max(maxi,vFences[j]-vFences[i]);
                }
            }
        }
        if(maxi==-1) return -1;
        long long mod=1e9+7;
        long long fin=maxi;
        int ans=((fin%mod)*(fin%mod)%mod)%mod;
        return ans;
    }
};