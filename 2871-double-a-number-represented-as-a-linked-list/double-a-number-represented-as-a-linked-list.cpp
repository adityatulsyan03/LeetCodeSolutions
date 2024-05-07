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
    ListNode* add(ListNode* l1, ListNode* l2){
        ListNode* newhead= new ListNode(0);
    ListNode* current = newhead;
    int carry=0;
    while(l1!=NULL || l2!=NULL){
        int a=(l1 != nullptr) ? l1->val : 0;
        int b=(l2 != nullptr) ? l2->val : 0;
        int sum=a+b+carry;
        carry=sum/10;
        current->next = new ListNode(sum % 10);
        current = current->next;

        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
    }
    if (carry > 0)
        current->next = new ListNode(carry);
    return newhead->next;
    }
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            
        }
        return prev;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        head = add(head,head);
        head = reverseList(head);
        return head;
    }
};