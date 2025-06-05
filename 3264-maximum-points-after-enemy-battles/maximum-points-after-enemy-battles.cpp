class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(),enemyEnergies.end());
        deque<int> dq(enemyEnergies.begin(),enemyEnergies.end());
        long long points=0;
        while(!dq.empty()){
            if(currentEnergy>=dq.front()){
                int temp=currentEnergy/dq.front();
                points+=temp;
                currentEnergy-=(dq.front()*temp);
            }
            else if(points>=1){
                currentEnergy+=dq.back();
                dq.pop_back();
            }
            else{
                break;
            }
        }
        return points;
    }
};