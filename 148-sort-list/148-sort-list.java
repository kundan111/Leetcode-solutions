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
    public ListNode sortList(ListNode head) {
        

        List<Integer> list = new ArrayList<>();

        ListNode temp1 = head;
        
        while (temp1 != null) {
            list.add(temp1.val);
            temp1 = temp1.next;
        }
        ListNode temp2 = head;

        Collections.sort(list);

        int curIndex = 0;
        while (temp2 != null) {
            temp2.val = list.get(curIndex++);
            temp2 = temp2.next;
        }

        

        
        return head;
    }
}