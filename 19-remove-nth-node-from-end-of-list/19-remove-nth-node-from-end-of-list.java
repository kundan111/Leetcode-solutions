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
    public ListNode removeNthFromEnd(ListNode head, int n) {
if(head == null)
        {
            return head;
        }
        ListNode temp = new ListNode();
        temp.next = head;
        ListNode fast = temp;
        ListNode slow = temp;


        int counter = 1;
        
        while (counter <= n) {
            
            fast = fast.next;
            counter++;
        }

        while(fast.next != null)
        {
            slow = slow.next;
            fast = fast.next;
        }


        slow.next = slow.next.next;
     
     
     
        return temp.next;
    }
}