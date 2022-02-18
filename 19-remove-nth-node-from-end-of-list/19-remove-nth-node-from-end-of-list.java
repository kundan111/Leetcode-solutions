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
        
        // first calculate the entire lenght
        int totalLen = 0;
        ListNode temp = head;

        while (temp != null) {
            totalLen++;
            temp = temp.next;
        }

        // distance from startin
        int lenFromStart = totalLen - n;

        if(lenFromStart == 0)
        {
            // first node to be removed

            head = head.next;
            return head;
        }

        int counter = 1;
        ListNode finalTemp = head;
        while (counter < lenFromStart) {
            finalTemp = finalTemp.next;
            counter++;
        }

        finalTemp.next = finalTemp.next.next;

        return head;
    }
}