class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int mx=-1,index=-1;
        for(int i=0;i<skills.size();i++){
            if(mx<skills[i]){
                mx=skills[i];
                index=i;
            }   
        }
        if(k>skills.size())
            return index;
        index=-1;
        int curr=0;
        deque<int> dq;
        for(int i=0;i<skills.size();i++)
            dq.push_back(i);
        while(curr!=k){
            int a=dq.front();
            dq.pop_front();
            int b=dq.front();
            if(skills[a]<skills[b]){
                dq.push_back(a);
                if(index==b)
                    curr++;
                else{
                    index = b;
                    curr=1;
                }
            }
            else{
                dq.pop_front();
                dq.push_front(a);
                dq.push_back(b);
                if(index==a)
                    curr++;
                else{
                    index=a;
                    curr=1;
                }
            }
        }
        return dq.front();
    }
};