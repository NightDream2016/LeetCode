#include "GlobalInclude.cpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode *mergeList(ListNode *firstList, ListNode *secondList)
    {
        // Merge two splited list sorted.
        // Using dummy node to keep code simple.
        ListNode *resultList = new ListNode(-1); 
        ListNode *resultTravelNode = resultList;
        
        while (firstList != NULL || secondList != NULL)
        {
            if (firstList == NULL)
            {
                resultTravelNode -> next = secondList;
                secondList = secondList -> next;
            }
            else if (secondList == NULL)
            {
                resultTravelNode -> next = firstList;
                firstList = firstList -> next;
            }
            else
            {
                if (firstList -> val > secondList -> val)
                {
                    resultTravelNode -> next = secondList;
                    secondList = secondList -> next;
                }
                else
                {
                    resultTravelNode -> next = firstList;
                    firstList = firstList -> next;
                }
            }
            
            resultTravelNode = resultTravelNode -> next;
        }
        
        resultList = resultList -> next;
        return resultList;
    }
    
    ListNode *sortList(ListNode* head) 
    {
        // If Only 1 or zero nodes, list is sorted.
        if (head == NULL || head -> next == NULL)
        {
            return head;
        }
        
        // Split List to two parts, Using fast & slow node method
        ListNode *firstTravelNode = head;
        ListNode *secondTravelNode = head;
        
        ListNode *previousNodeOfFirst = NULL;
        while (firstTravelNode -> next != NULL && secondTravelNode -> next != NULL)
        {
            previousNodeOfFirst = firstTravelNode;
            firstTravelNode = firstTravelNode -> next;
            secondTravelNode = (secondTravelNode -> next) -> next;
            
            if (firstTravelNode == NULL || secondTravelNode == NULL)
            {
                break;
            }
        }
        
        previousNodeOfFirst -> next = NULL;
        
        // Doing merge sort of two parts
        ListNode *firstList = head;
        ListNode *secondList = firstTravelNode;
        
        // Split Recursively and merge Them.
        return mergeList(sortList(firstList), sortList(secondList));
    }
};
// @lc code=end
