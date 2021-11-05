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
        
        ListNode* sorting;
        
        if(l1 == NULL)
        {
            return l2;
        }
        if(l2 == NULL)
        {
            return l1;
        }
        
        if(l1->val <= l2->val)
        {
            sorting = l1;
            l1 = sorting->next;
        }else{
            sorting = l2;
            l2 = sorting->next;
        }
        
        ListNode* mergedHead = sorting;
        
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                sorting->next = l1;
                sorting = l1;
                l1 = sorting->next;
            }else{
                sorting->next = l2;
                sorting = l2;
                l2 = sorting->next;
            }
        }
        
        
        if(l1 == NULL)
        {
            sorting->next = l2;
        }
        
        if(l2 == NULL)
        {
            sorting->next = l1;
        }
        
        return mergedHead;
        
        
        
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                
                // cout << i << " -> " <<  len - 1 - i << endl;
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }
        
        return lists.front();
    }
};