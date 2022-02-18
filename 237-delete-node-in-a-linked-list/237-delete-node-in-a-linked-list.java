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
        ListNode nextNode = node.next;
        // swap the nextNode and node and values
        int temp = node.val;
        node.val = nextNode.val;
        nextNode.val = temp;
        node.next = nextNode.next;
        
    }
}