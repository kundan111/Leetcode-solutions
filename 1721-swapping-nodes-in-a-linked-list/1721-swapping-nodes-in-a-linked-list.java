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
     
        int count = 0;
        ListNode first = head;

        while (count < k-1) {
            first = first.next;
            count++;
        }

        ListNode tempNode = first;

        ListNode second = head;

        while (first.next != null) {
            first = first.next;
            second = second.next;
        }


        int temp = tempNode.val;
        tempNode.val = second.val;
        second.val = temp;


        return head;
    }
}