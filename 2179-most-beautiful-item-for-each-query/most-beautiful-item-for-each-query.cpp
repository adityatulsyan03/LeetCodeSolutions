class Solution {
private:
    int find(int num,vector<vector<int>>& items){
        int s=0,e=items.size()-1;
        int index=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(items[mid][0]<=num){
                index = mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return index;
    }
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int max_val = 0;
        for (auto& item : items) {
            max_val = max(max_val, item[1]);
            item[1] = max_val;
        }
        vector<int> ans;
        for (int i : queries) {
            int temp = find(i, items);
            if (temp == -1) {
                ans.push_back(0);
            } else {
                ans.push_back(items[temp][1]);
            }
        }
        
        return ans;
    }
};