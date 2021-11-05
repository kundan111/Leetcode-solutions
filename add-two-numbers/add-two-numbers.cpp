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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  
        ListNode* resHead = new ListNode(-1);
        ListNode* temp = resHead;
        
        
        ListNode* l1Holder = l1;
        ListNode* l2Holder = l2;
        
        int carry = 0;
        
        int val1 = 0;
        int val2 = 0;
        
        while(l1Holder || l2Holder)
        {
            if(!l1Holder)
            {
                val1 = 0;
            }else{
                val1 = l1Holder->val;
            }
            
            if(!l2Holder)
            {
                val2 = 0;
            }else{
               val2 =  l2Holder->val;
            }
            
            int curSum = ( val1 + val2 + carry);
            int curDigit =  curSum % 10;
            carry = curSum/10;
            
            temp->next = new ListNode(curDigit);
            temp = temp->next;
            
            if(l1Holder)
            {
               l1Holder = l1Holder->next; 
            }
            if(l2Holder)
            {
               l2Holder = l2Holder->next; 
            }
            
        }
        
        if(carry)
        {
            temp->next = new  ListNode(1);    
        }
        
        return resHead->next;
    }
};