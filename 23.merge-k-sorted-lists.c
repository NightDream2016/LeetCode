#include <stdio.h>
#include <stdlib.h>
/*
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (29.77%)
 * Total Accepted:    256.6K
 * Total Submissions: 861.9K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode 
{
    int val;
    struct ListNode *next;
};
typedef struct ListNode LISTNODE;

struct ListNode *mergeList(LISTNODE *listA, LISTNODE *listB)
{
    if (listA == NULL && listB == NULL)
    {
        return NULL;
    }

    if (listA == NULL)
    {
        return listB;
    }
    
    if (listB == NULL)
    {
        return listA;
    }

    LISTNODE *newListHead = NULL;

    if (listA->val >= listB->val)
    {
        newListHead = listB;
        listB = listB->next;
    }
    else
    {
        newListHead = listA;
        listA = listA->next;
    }
    
    newListHead->next = mergeList(listA, listB);

    return newListHead;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) 
{
    LISTNODE *list = NULL;
    for (int i = 0; i < listsSize; i++)
    {
        list = mergeList(list, lists[i]);
    }    

    return list;
}
