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
            return list1 == null ? list2 : list1;
        }
        

        // both are not null nodes

        ListNode first = list1;
        ListNode second = list2;

        ListNode head = new ListNode();
        ListNode lastAdded = head;


        while (first != null || second != null) {
            
            if(first == null)
            {
                lastAdded.next = second;
                break;
            }

            if(second == null)
            {
                lastAdded.next = first;
                break;
            }


            if(first.val <= second.val)
            {
                ListNode nn = new ListNode(first.val);
                lastAdded.next = nn;
                first = first.next;
            }else{
                ListNode nn = new ListNode(second.val);
                lastAdded.next = nn;
                second = second.next;
            }

            lastAdded = lastAdded.next;

        }


        
        return head.next;
    }
}