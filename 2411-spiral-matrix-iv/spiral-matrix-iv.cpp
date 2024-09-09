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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int i=0,j=0;
        int ii=0,jj=0;
        while (head != nullptr) {
            // Traverse from left to right
            while (j < n && ans[i][j] == -1 && head != nullptr) {
                ans[i][j] = head->val;
                head = head->next;
                // cout<<i<<" "<<j<<" "<<ans[i][j]<<endl;
                j++;
            }
            j--;
            i++;

            // Traverse from top to bottom
            while (i < m && ans[i][j] == -1 && head != nullptr) {
                ans[i][j] = head->val;
                head = head->next;
                // cout<<i<<" "<<j<<" "<<ans[i][j]<<endl;
                i++;
            }
            i--;
            j--;

            // Traverse from right to left
            while (j >= jj && ans[i][j] == -1 && head != nullptr) {
                ans[i][j] = head->val;
                head = head->next;
                // cout<<i<<" "<<j<<" "<<ans[i][j]<<endl;
                j--;
            }
            j++;
            i--;

            // Traverse from bottom to top
            while (i >= ii && ans[i][j] == -1 && head != nullptr) {
                ans[i][j] = head->val;
                head = head->next;
                // cout<<i<<" "<<j<<" "<<ans[i][j]<<endl;
                i--;
            }
            i++;
            j++;
            m--;
            n--;
            ii++;
            jj++;
        }

        return ans;
    }
};