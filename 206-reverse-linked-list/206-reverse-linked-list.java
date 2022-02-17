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
    public ListNode reverseList(ListNode head) {
        if(head == null)
        {
            return head;
        }

        ListNode prev = null;
        ListNode cur = head;
        ListNode nxt = head.next;

        while (cur != null) {
            cur.next = prev;
            prev = cur;
            cur = nxt;
            if(nxt != null)
            {
                nxt = nxt.next;
            }
        }

        return prev;
        
    }
}