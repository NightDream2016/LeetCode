#include "GlobalInclude.cpp"
/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *reverseList(ListNode *head)
    {
        ListNode *previous = NULL;
        ListNode *current = head;
        ListNode *nextHead = head -> next;

        while (nextHead != NULL)
        {
            current -> next = previous;
            previous = current;
            current = nextHead;
            nextHead = nextHead -> next;
        }

        current -> next = previous;

        return current;
    }

    bool isPalindrome(ListNode* head) 
    {
        if (head == NULL)
        {
            return true;
        }

        ListNode *firstList = head;
        ListNode *secondList = head;

        while (firstList != NULL && secondList != NULL)
        {
            if (secondList -> next == NULL)
            {
                break;
            }
            
            firstList = firstList -> next;
            secondList = secondList -> next -> next;
        }

        secondList = reverseList(firstList);
        firstList = head;

        bool result = true;
        while (firstList != NULL && secondList != NULL)
        {
            if (firstList -> val != secondList -> val)
            {
                result = false;
                break;
            }
            firstList = firstList -> next;
            secondList = secondList -> next;
        }

        return result;

    }
};
// @lc code=end
int main(int argc, char *argv[])
{
    vector<int> vectorInput = {1,2,3,2,1};
    ListNode *list = listFromVector(vectorInput);
    Solution solution;
    solution.isPalindrome(list);

    return 0;
}
