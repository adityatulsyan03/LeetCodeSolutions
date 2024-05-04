class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1,cnt=0;
        while(j>=0 && people[j]>=limit)
            cnt++,j--;
        while(i<j){
            if(people[i]+people[j]>limit){
                j--;
                cnt++;
            }
            else{
                i++;
                j--;
                cnt++;
            }
        }
        if(i==j)
            cnt++;
        return cnt;
    }
};