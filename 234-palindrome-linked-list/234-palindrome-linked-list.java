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
    public boolean isPalindrome(ListNode head) {
        

        if(head == null)
        {
            return true;
        }
        ListNode endOfFirstHalf = endOfFirstHalf(head);
        ListNode secondHalfStart = reverseLinkedList(endOfFirstHalf.next);

        boolean result = true;

        ListNode p1 = head;
        ListNode p2 = secondHalfStart;


        while (result && p2 != null) {
            if(p1.val != p2.val)
            {
                result = false;
            }

            p1 = p1.next;
            p2 = p2.next;
        }

        endOfFirstHalf.next = reverseLinkedList(secondHalfStart);
        
        return result;
    }

    ListNode endOfFirstHalf(ListNode head)
    {
        ListNode slow = head;
        ListNode fast = head;

        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    ListNode reverseLinkedList(ListNode head)
    {
        
        if(head == null)
        {
            return null;
        }

        if(head.next == null)
        {
            return head;
        }

        ListNode newNode = reverseLinkedList(head.next);
        head.next.next = head;
        head.next = null;

        return newNode;

        
    }
}