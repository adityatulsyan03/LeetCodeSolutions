class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        vector<int> left(height.size(),0),right(height.size(),0);
        for(int i=0;i<height.size();i++){
            left[i]=max(left[(i>0)?i-1:i],height[i]);
            int r=height.size()-1-i;
            right[r]=max(right[(r<height.size()-1)?r+1:r],height[r]);
        }
        for(int i=0;i<height.size();i++){
            ans+= (min(left[i],right[i])-height[i]);
        }
        return ans;
    }
};