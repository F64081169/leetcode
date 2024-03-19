class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* mergeList = new ListNode(); 
        ListNode* head = mergeList; 

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                mergeList->next = list1;
                list1 = list1->next;
            } else {
                mergeList->next = list2;
                list2 = list2->next;
            }
            mergeList = mergeList->next;
        }

        mergeList->next = list1 ? list1 : list2;

        return head->next;
    }
};
