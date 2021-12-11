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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // not optimised
        int len = 0;
        auto temp = head;
        while(temp)
        {
            len++;
            temp = temp->next;
        }
        
        int fromStart = len - n;
        
        if(fromStart == 0)
        {
            
            head = head->next;
            return head;
        }
        
        int i = 0;
        temp = head;
        
        
        while(i < fromStart-1)
        {
            temp = temp->next;
            i++;
        }
        
        temp->next = temp->next->next;
        
        return head;
        
        
        
        
    }
};