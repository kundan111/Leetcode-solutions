/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
     public void deleteNode(ListNode node) {
        
        // this is not null
        ListNode nextNode = node.next;

        // copy node to nextNode

        int delValue = node.val;
        node.val = nextNode.val;
        nextNode.val = delValue;


        node.next = node.next.next;

    }
}