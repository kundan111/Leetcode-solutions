/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        
        ListNode tempA = headA;
        ListNode tempB = headB;

        // while (tempA != null && tempB != null) {
        //     tempA = tempA.next;
        //     tempB = tempB.next;
        // }


        HashMap<ListNode,Integer> hm = new HashMap<>();
        while (tempA != null) {
            hm.put(tempA, 1);
            tempA = tempA.next;
        }
        while (tempB != null) {
            if(hm.containsKey(tempB))
            {
                return tempB;
            }
            tempB = tempB.next;
        }


        return null;
    }
}