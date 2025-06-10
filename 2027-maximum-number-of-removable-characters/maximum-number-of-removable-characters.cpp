class Solution {
private:
    bool check(string s,string p){
        int i = 0, j = 0;
        while (i < s.length() && j < p.length()) {
            if (s[i] != '/' && s[i] == p[j]) {
                j++;
            }
            i++;
        }
        return j == p.length();
    }
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n=removable.size();
        int l=0,r=n;
        string temp=s;
        while(l<=r){
            int mid = l-(l-r)/2;
            for(int i=0;i<mid;i++)
                temp[removable[i]]='/';
            if(check(temp,p))  l=mid+1;
            else{
                for(int i=0;i<mid;i++)
                    temp[removable[i]]=s[removable[i]];
                r=mid-1;
            }
        }
        return r;
    }
};