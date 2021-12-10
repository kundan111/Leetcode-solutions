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
    bool hasCycle(ListNode *head) {
        ListNode * tempRoot = head;
        unordered_map<ListNode*, int>m;
        while(tempRoot)
        {
            m[tempRoot]++;
            if(m[tempRoot] > 1)
            {
                return true;
            }
        
        tempRoot = tempRoot->next;
        }
        
        
        return false;
    }
    
    
};