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
    public ListNode swapNodes(ListNode head, int k) {
        
        
        int totalLen = llLength(head);
        int lengthFromFront  = totalLen - k;

        int gotFromFront = lengthFromFront;

        ListNode firstPoiter = head;
        ListNode secondPoiter = head;

        int count = 0;
        while (count < k-1) {
            firstPoiter = firstPoiter.next;
            count++;
        }

        count = 0;
        while (count < gotFromFront) {
            secondPoiter = secondPoiter.next;
            count++;
        }


        // swap these two nodes
        int temp = firstPoiter.val;
        firstPoiter.val = secondPoiter.val;
        secondPoiter.val = temp;        


     
        return head;
    }
    

    int llLength(ListNode head)
    {
        int len = 0;
        ListNode temp = head;

        while (temp != null) {
            len++;
            temp = temp.next;
        }

        return len;
    }
}