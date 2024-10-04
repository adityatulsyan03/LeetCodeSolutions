class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long ans=skill[0]*skill[skill.size()-1];
        for(int i=1;i<skill.size()/2;i++){
            long long prev=skill[i-1]+skill[skill.size()-i];
            long long curr=skill[i]+skill[skill.size()-i-1];
            if(curr!=prev)  return -1;
            else    ans+=skill[i]*skill[skill.size()-i-1];
        }
        return ans;
    }
};