class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> num;
        for(int i=0;i<arr.size();i++){
            if(num.find(arr[i]*2)!=num.end() || 
                (num.find(arr[i]/2)!=num.end() && arr[i]%2==0) ){
                return 1;
            }
            num.insert(arr[i]);
        }
        return 0;
    }
};