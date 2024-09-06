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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> cnt;
        for(int i:nums){
            cnt[i]++;
        }
        while (head != nullptr && cnt[head->val] != 0) {
            head = head->next;
        }
        ListNode* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (cnt[temp->next->val] != 0) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};