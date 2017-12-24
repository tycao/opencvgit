#include <vector>
#include <iostream>
#include "remove_duplicates_from_sorted_list.h"

using std::vector;
typedef vector<int>::iterator vecIter;

ListNode* createLinkedList(vecIter beg, vecIter end) {
    ListNode* head = beg == end ? nullptr : new ListNode(*beg++);
    for (ListNode* cur = head; beg != end; cur = cur->next) {
        cur->next = new ListNode(*beg++);
    }
    return head;
}

void printAndClear(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << "->";
        ListNode* del = head;
        head = del->next;
        delete del;
    }
    std::cout << std::endl << std::endl;
}

int main(int argc, char *argv[])
{
    vector<int> vec{1, 1, 2};
    vector<int> vec2{1, 1, 2, 3, 3};

    ListNode* head = createLinkedList(vec.begin(), vec.end());
    ListNode* head2 = createLinkedList(vec2.begin(), vec2.end());

    Solution s;
    ListNode* res = s.deleteDuplicates(head);
    ListNode* res2 = s.deleteDuplicates(head2);

    printAndClear(res);
    printAndClear(res2);

    return 0;
}
