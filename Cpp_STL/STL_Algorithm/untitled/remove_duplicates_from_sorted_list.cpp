#include "remove_duplicates_from_sorted_list.h"

ListNode::ListNode(int x) : val(x), next(nullptr) { }


ListNode* Solution::deleteDuplicates(ListNode* head) {
    for (ListNode* cur = head; cur && cur->next; ) {
        if (cur->val == cur->next->val) {
            ListNode* del = cur->next;
            cur->next = del->next;
            delete del;
        }
        else {
            cur = cur->next;
        }
    }
    return head;
}
