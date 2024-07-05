/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    void helper(ListNode* head,vector<int>& ans){
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* next=head->next->next;
        int a=2;
        vector<int> temp;
        while(next!=NULL){
            if((prev->val<curr->val && next->val<curr->val) || (prev->val>curr->val && next->val>curr->val)){
                temp.push_back(a);
            }
            a++;
            prev=prev->next;
            curr=curr->next;
            next=next->next;
        }
        if(temp.size()>1){
            ans[0]=temp[1]-temp[0];
            for(int i=1;i<temp.size()-1;i++){
                ans[0]=min(ans[0],temp[i+1]-temp[i]);
            }
            ans[1]=temp[temp.size()-1]-temp[0];
        }
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2,-1);
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return ans;
        helper(head,ans);
        return ans;
    }
};