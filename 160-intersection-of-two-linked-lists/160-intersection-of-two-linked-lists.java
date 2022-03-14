/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode tempA = headA;
        ListNode tempB = headB;


        int countA = 0;
        int countB = 0;

        while (tempA != null || tempB != null) {
            
            if(tempA != null && tempA == tempB)
            {
                return tempA;
            }

            if(tempA != null)
            {
                tempA = tempA.next;
                countA++;
            }

            if(tempB != null)
            {
                tempB = tempB.next;
                countB++;
            }
        }

        // Both are of different length
        int diff = Math.abs(countA-countB);

        ListNode longer = null;
        ListNode shorter = null;

        if(countA > countB)
        {
            longer = headA;
            shorter = headB;
        }else{
            longer = headB;
            shorter = headA;
        }

        int count = 0;
        while (count != diff) {
            longer = longer.next;
            count++;
        }

        while (longer != null &&  shorter != null) {
            
            if(longer == shorter)
            {
                return longer;
            }

            longer = longer.next;
            shorter = shorter.next;
        }

        
        return null;
    }
}