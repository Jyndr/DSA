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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mini = INT_MAX, maxi = INT_MIN;
        int first_critical = -1, recent_critical = -1;

        ListNode* prev = head;
        ListNode* temp = head->next;
        int idx = 1;

        while (temp->next) {
            ListNode* nextt = temp->next;
            int a = prev->val;
            int b = temp->val;
            int c = nextt->val;

            if (b > a && b > c) { // local maxima
                if (first_critical != -1) {
                    maxi = max(maxi, idx - first_critical);
                }
                if (recent_critical != -1) {
                    mini = min(mini, idx - recent_critical);
                }
                if (first_critical == -1) {
                    first_critical = idx;
                }
                recent_critical = idx;
            } else if (a > b && c > b) { // local minima
                if (first_critical != -1) {
                    maxi = max(maxi, idx - first_critical);
                }
                if (recent_critical != -1) {
                    mini = min(mini, idx - recent_critical);
                }
                if (first_critical == -1) {
                    first_critical = idx;
                }
                recent_critical = idx;
            }
            idx++;
            prev = temp;
            temp = nextt;
        }

        if(mini == INT_MAX){
            return {-1 , -1};
        }
        return {mini, maxi};
    }
};