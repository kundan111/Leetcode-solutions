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
    
        ListNode* t = head;
        int prev = t->val;
        t = t->next;
        int minDis = -1, maxDis = -1;
        
        
        
        vector<int> temp;
        
        int count = 1;
        while(t->next)
        {
               
           if((t->val > prev && t->val > t->next->val) || (t->val < prev && t->val < t->next->val))
           {
               temp.push_back(count);
            }
            prev = t->val;


            t = t->next;
            count++;
        }
        
        
        if(temp.size() > 1)
        {
            int i = 0;
            int j = 1;
            int mn = INT_MAX;
            while(j < temp.size())
            {
                mn = min(mn,temp[j] - temp[i]);
                i++;
                j++;
            }
            
            return {mn, temp[temp.size()-1] - temp[0]};
            
        }
        
        return {minDis, maxDis};
    }
};