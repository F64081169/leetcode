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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head; // 0 element
        if (head->next == nullptr) return head;// 1 element
        if (head->next->next == nullptr) {// 2 element
            ListNode* p = head->next;
            p->next = head;
            head->next = nullptr;
            return p;
        }
        // 1 -> 2 -> 3
        // pre -> 1, cur -> 2
        // nxt -> 3 (p->next)
        // 2 -> pre,pre=cur,cur=nxt,nxt=nxt->next
        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* nxt = head->next->next;

        while(nxt!=nullptr){
            cur->next = pre;
            pre = cur;
            cur = nxt;
            nxt=nxt->next;
        }

        cur->next = pre;
        head->next = nullptr;
        return cur;
        
    }
};
