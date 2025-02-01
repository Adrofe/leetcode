/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <stdlib.h>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            addList(l1, sum);
            addList(l2, sum);

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummy->next;
    }

private:
    /**
     * @brief Adds the value of the current node of the list to the sum and advances the list to the next node.
     * 
     * @param list A reference to a pointer to the current node of the list. The pointer will be advanced to the next node.
     * @param sum A reference to an integer that will be incremented by the value of the current node of the list.
     */
    void addList(ListNode*& list, int& sum) {
        if (list != nullptr) {
            sum += list->val;
            list = list->next;
        }
    }
};