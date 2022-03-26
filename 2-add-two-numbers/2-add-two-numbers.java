/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        if(l1 == null || l2 == null)
        {
            return l1 == null ? l2 : l1;
        }
        
        ListNode temp1 = l1;
        ListNode temp2 = l2;

        int carry = 0;
        
        // int firstVal = 0;
        // int secondVal = 0;

        ListNode resultantHead = new ListNode(-1);
        ListNode finalNode = resultantHead;

        while (temp1 != null || temp2 != null) {

            int firstVal = 0;
            int secondVal = 0;
            
            if(temp1 != null)
            {
                firstVal = temp1.val;
                temp1 = temp1.next;
            }
            

            if(temp2 != null)
            {
                secondVal = temp2.val;
                temp2 = temp2.next;
            }

            int result = firstVal + secondVal + carry;
            
            carry = result > 9 ? 1 : 0;
            int unitVal = result%10;


            // create a new node

            resultantHead.next = new ListNode(unitVal);
            resultantHead = resultantHead.next;

        }

        if(carry != 0)
        {
            resultantHead.next = new ListNode(1);
        }

     
        return finalNode.next;
    }
}