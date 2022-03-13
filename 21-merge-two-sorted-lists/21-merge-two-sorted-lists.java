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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        
        if(list1 == null || list2 == null)
        {
            return list1 != null ? list1 : list2;
        }

        ListNode l1 = list1;
        ListNode l2 = list2;
        
if(list1.val > list2.val)
        {
            l1 = list2;
            l2 = list1;
        }

        ListNode res = l1;

        while (l1 != null && l2 != null) {
            
            ListNode temp = null;
            while (l1 != null && l1.val <= l2.val) {
                temp = l1;
                l1 = l1.next;
            }

            temp.next = l2;

            // swap l1 and l2
            ListNode t = l1;
            l1 = l2;
            l2 = t;
        }
        
        return res;
    }
}