struct node{
    public:
    int data;
    int i;
    int j;

    node(int data,int i,int j){
        this->data=data;
        this->i=i;
        this->j=j;
    }
};

class compare{
public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mx = numeric_limits<int>::min();
        int mn = numeric_limits<int>::max();
        priority_queue<node*,vector<node*>,compare> min_heap;
        for(int i=0;i<nums.size();i++){
            mn=min(mn,nums[i][0]);
            mx=max(mx,nums[i][0]);
            min_heap.push(new node(nums[i][0],i,0));
        }
        int start=mn,end=mx;

        while(!min_heap.empty()){
            node* temp=min_heap.top();
            min_heap.pop();

            mn= temp->data;

            if(mx-mn < end-start){
                start=mn;
                end=mx;
            }

            if(temp->j+1 < nums[temp->i].size()){
                mx=max(mx,nums[temp->i][temp->j +1]);
                min_heap.push(new node(nums[temp->i][temp->j+1],temp->i,temp->j+1));
            }
            else{
                break;
            }
        }
        vector<int> ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};