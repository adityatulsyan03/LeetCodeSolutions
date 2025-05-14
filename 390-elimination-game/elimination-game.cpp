class Solution {
public:
    int lastRemaining(int n) {
        int remaning = n;
        bool left = true;
        int head = 1;
        int step=1;
        while(remaning>1){
            if(left || remaning%2==1){
                head+=step;
            }
            step*=2;
            remaning/=2;
            left = !left;
        }
        return head;
    }
};