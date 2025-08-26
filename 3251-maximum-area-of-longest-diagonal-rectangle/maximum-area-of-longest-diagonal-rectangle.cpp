class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int index=0;
        float prev=0;
        for(int i=0;i<dimensions.size();i++){
            float val=sqrt((dimensions[i][0]*dimensions[i][0])+(dimensions[i][1]*dimensions[i][1]));
            if(val>prev){
                prev=val;
                index=i;
            }
            if(val==prev){
                int s=(dimensions[i][0]*dimensions[i][1]);
                if((dimensions[index][0]*dimensions[index][1])<s){
                    index=i;
                }
            }
        }
        return (dimensions[index][0]*dimensions[index][1]);
    }
};