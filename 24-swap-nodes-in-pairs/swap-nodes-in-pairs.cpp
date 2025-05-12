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
    ListNode* solve(ListNode* first, ListNode* second) {
        if (first == nullptr || second == nullptr) {
            return first;
        }

        ListNode* nextPair = second->next;
        second->next = first;
        first->next = solve(nextPair, nextPair ? nextPair->next : nullptr);
        return second;
    }

public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        return solve(head, head->next);
    }
};