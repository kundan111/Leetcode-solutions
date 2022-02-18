/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
                
        
        ListNode slow = head;
        ListNode fast = head;

        boolean isLoopDetected = false;
        
        while (fast != null && fast.next != null) {
            
            slow = slow.next;
            fast = fast.next.next;

            if(slow == fast)
            {
                isLoopDetected = true;
                break;
            }

        }
        
        if(!isLoopDetected)
        {
            return null;

        }

        // there is a loop 

        ListNode entry = head;

        while (entry != slow) {
            entry = entry.next;
            slow = slow.next;
        }

        return entry;
    }
}