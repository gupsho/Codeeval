/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head == NULL || head->next == NULL || m == n)
            return head;
        ListNode* first = head, *second, *third, *prev = NULL;
        int count = 1;
        while(count < m ) {
            prev = first;
            first = first->next;
            count++;
        }
        second = first;
        first = NULL;
        ListNode* newTail = second;
        while(count <= n) {
            third = second->next;
            second->next = first;
            first = second;
            second = third;
            count++;
        }
        if(prev) 
            prev->next = first;
        else
            head = first;
        newTail->next = second;
        return head;
    }
};
