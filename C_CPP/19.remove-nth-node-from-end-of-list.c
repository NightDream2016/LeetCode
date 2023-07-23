#include "stdlib.h"
#include "stdio.h"

/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (33.78%)
 * Total Accepted:    271.4K
 * Total Submissions: 803.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode 
{
    int val;
    struct ListNode *next;
}
LISTNODE;

LISTNODE *createListNode (int val, LISTNODE *next)
{
    LISTNODE *node = (LISTNODE *)malloc(sizeof(LISTNODE));
    node->val = val;
    node->next = next;
    return node;
}

LISTNODE *listPush(LISTNODE *listhead, int val)
{
    LISTNODE *newNode = createListNode(val, listhead);
    return newNode;
}

LISTNODE *listPop(LISTNODE *listhead)
{
    LISTNODE *lastHead = listhead;
    listhead = listhead->next;
    free(lastHead);
    return listhead;
}

LISTNODE *createListFromArray(int array[], int arrayLength)
{
    LISTNODE *head = NULL;
    for (int i = 0; i < arrayLength; i++)
    {
        head = listPush(head, array[i]);
    }

    return head;
}


void listOutput(LISTNODE *head)
{
    printf("[");
    while (head != NULL)
    {
        printf("%d, ", head->val);
        head = head -> next;
    }

    printf("]\n");
}


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    struct ListNode *node = head;
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    int listHeadArrayLength = n + 1;
    struct ListNode **listHeadArray = (struct ListNode **)malloc(sizeof(struct ListNode*) * listHeadArrayLength);

    int i = 0;

    while (node != NULL)
    {
        // printf("node:%p ", node);
        // printf("node:%d\n", node->val);
        listHeadArray[i % listHeadArrayLength] = node;
        // printf("listHeadArray[%d]:%p\n", i % listHeadArrayLength, node);
        node = node->next;
        i++;
    }
    // printf("i:%d\n", i);
    int removeHeadIndex = i - n;
    int lastHeadIndex = removeHeadIndex - 1;

    struct ListNode *removeHead = listHeadArray[removeHeadIndex % listHeadArrayLength];

    if (removeHeadIndex == 0)
    {
        head = head->next;
    }
    else
    {
        struct ListNode *lastHead = listHeadArray[lastHeadIndex % listHeadArrayLength];
        
        // printf("lastHead:%d", lastHead->val);
        // printf("removeHead:%d", removeHead->val);
        lastHead->next = removeHead->next;
    }

    free(removeHead);
    
    return head;
}


int main(int argc, char ** argv)
{

    int input[] =  {1,2,3,4,5};

    LISTNODE *list = createListFromArray(input, 5);

    listOutput(list);

    LISTNODE *result = removeNthFromEnd(list, 2);

    listOutput(result);

    return 0;
}

