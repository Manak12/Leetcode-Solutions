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

    // function to reverse the list
    ListNode *reverse(ListNode *head){
        ListNode *cur = head;
        ListNode *prev = NULL;
        ListNode *temp = NULL;

        while(cur != NULL){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        if(head->next == NULL){
            return head->val;
        }

        // finding the mid of the linklist
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
         
        ListNode *head2 = reverse(slow->next);

        int maxi = INT_MIN;
        while(head2 != NULL){
            int sum = head->val + head2->val;
            maxi = max(maxi, sum);
            head = head->next;
            head2 = head2->next;
        }

        return maxi;
    }
};