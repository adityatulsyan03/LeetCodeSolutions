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
public:
    int getDecimalValue(ListNode* head) {
        int n=-1;
        ListNode* temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int ans=0;
        temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" "<<n<<endl;
            if(temp->val == 1)
                ans+= pow(2,n--);
            else
                n--;
            temp=temp->next;
        }
        return ans;
    }
};