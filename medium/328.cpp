/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = head;
        if(head == NULL || head->next==nullptr) return head;
        ListNode* even = head->next;
        ListNode* even_start = head->next;
        

        while(odd->next!=nullptr && even->next!=nullptr){
            // odd 
            odd->next = even->next;
            //even
            even->next = odd->next->next;
            
            odd = odd->next;
            even = even->next;
        }

        odd->next = even_start;
        return head;
    }
};
