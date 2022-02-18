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
                
        if(head == null)
        {
            return head;
        }

        ListNode res = null;
        ListNode temp = head;

        HashMap<ListNode,Integer> hm = new HashMap<>();

        while (temp != null) {
            if(hm.containsKey(temp))
            {
                res = temp;
                break;
            }
            hm.put(temp, 1);
            temp = temp.next;

        }

        return res != null ? res : null;
    }
}