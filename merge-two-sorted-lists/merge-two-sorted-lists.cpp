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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1 || !l2)
        {
            return !l1 ? l2 : l1;
        }
        
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* sorting;
        
        if(ptr1->val <= ptr2->val)
        {
            sorting = ptr1;
            ptr1 = ptr1->next;
            
        }else{
            sorting = ptr2;
            ptr2 = ptr2->next;
        }
        
        ListNode* mergedHead = sorting;
        
        while(ptr1 && ptr2)
        {
            
            if(ptr1->val <= ptr2->val)
            {
                sorting->next = ptr1;
                sorting = ptr1;
                ptr1 = sorting->next;
            }else{
                sorting->next = ptr2;
                sorting = ptr2;
                ptr2 = sorting->next;
            }
        }
        
        if(ptr1 == nullptr)
        {
            sorting->next = ptr2;
        }
        
        if(ptr2 == nullptr)
        {
            sorting->next = ptr1;
        }
        
        return mergedHead;
    }
};