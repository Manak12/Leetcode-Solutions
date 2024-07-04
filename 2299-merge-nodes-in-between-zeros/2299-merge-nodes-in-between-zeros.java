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
    public ListNode mergeNodes(ListNode head) {
        ListNode prev=head.next, curr=head.next;
        int sum=0;
        for (; curr!=null; curr=curr.next){
            int x=curr.val;
            if (x!=0) sum+=x;
            else{
                prev.val=sum;
                prev.next=curr.next;
                prev=prev.next;
                sum=0;
            }
        } 
        return head.next;
    }
}