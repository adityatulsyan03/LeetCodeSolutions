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
    void solve(ListNode* temp, int data){
        if(temp==nullptr || temp->next == nullptr){
            return;
        }
        if(temp->next->val==data){
            temp->next=temp->next->next;
            solve(temp, data);
        }else{
            solve(temp->next, data);
        }
    }
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            head = head->next;
        }
        ListNode* temp=head;
        solve(temp,val);
        return head;
    }
};