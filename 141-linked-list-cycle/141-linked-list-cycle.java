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
    private boolean res = false;

    public boolean hasCycle(ListNode head) {
     
        HashMap<ListNode,Integer> hm = new HashMap<>();

        ListNode tempHead = head;

        while (tempHead != null) {
            if(hm.containsKey(tempHead))
            {
                res = true;
                break;
            }
            hm.put(tempHead, 1);
            tempHead = tempHead.next;
        }

        return res;
    }
}