#pragma once

struct ListNode
{
    // constructor
    ListNode(int x);

    // member data
    int val = 0;
    ListNode* next = nullptr;
};

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head);
};
