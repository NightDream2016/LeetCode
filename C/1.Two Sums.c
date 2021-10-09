#include "stdio.h"
#include "stdlib.h"
#define HASHTABLE_SIZE 3989

int hash(int value)
{
    int key = abs(value) % HASHTABLE_SIZE;
    return key;
}

typedef struct hashTableNode
{
    int value;
    int indexOfValue;
    struct hashTableNode *nextNode;
}
HashTableNode;

// 找出HashTable中value為valueToFind但indexOfValue不為filteredIndexOfValue的Node
HashTableNode *hashTableFindValueWithFilter(HashTableNode *mapArray, int valueToFind, int filteredIndexOfValue)
{   
    int key = hash(valueToFind);
    
    HashTableNode *currentNode = &(mapArray[key]);
    
    int result = 0;

    while (currentNode != NULL) 
    {
        if (currentNode->indexOfValue == -1)
        {
            break;
        }
        
        if (currentNode->value == valueToFind && currentNode->indexOfValue != filteredIndexOfValue)
        {
            // printf("HashTable Find Value:%d IndexOfValue:%d With HashKey:%d\n",currentNode->value, currentNode->indexOfValue, key);
            
            result = 1;
            break;
        }
        
        currentNode = currentNode->nextNode;   
    }
  
    if (result)
    {
        return currentNode;
    }
    
    return NULL;
}


void hashTablePutValue(HashTableNode *mapArray, int valueToPut, int indexOfValueToPut)
{   
    int key = hash(valueToPut);
    
    HashTableNode *currentNode = &(mapArray[key]);
    
    int result = 0;
    
    while (currentNode != NULL)
    {
        
        // No Collision
        if (currentNode->indexOfValue == -1)
        {
            currentNode->value = valueToPut;
            currentNode->indexOfValue = indexOfValueToPut;
            // printf("HashTable Put Value:%d, indexOfValue:%d With HashKey:%d\n",valueToPut, indexOfValueToPut, key);
            break;
        }
        
        // Collsion
        if (currentNode->nextNode == NULL)
        {
            // Create New Node
            HashTableNode *nextNode =  (HashTableNode *)malloc(sizeof(HashTableNode) * 1);
            nextNode->value = 0;
            nextNode->indexOfValue = -1;
            nextNode->nextNode = NULL;
            currentNode->nextNode = nextNode;
        }
        
        // Chaining Find Next Node
        currentNode = currentNode->nextNode;   
    }
}


void *swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return 0;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target)
{
    int *result = (int *)malloc(sizeof(int) * 2);
    
    // Initialize Hash Table
    HashTableNode *mapArray = (HashTableNode *)malloc(sizeof(HashTableNode) * HASHTABLE_SIZE);
    
    for (int i = 0; i< HASHTABLE_SIZE; i++) // O(n)
    {
        mapArray[i].value = 0;
        mapArray[i].indexOfValue = -1;
        mapArray[i].nextNode = NULL;
    }
    
    // Put hash Table
    for (int i = 0; i<numsSize; i++)    // O(n)
    {        
        hashTablePutValue(mapArray, nums[i], i);
    }
    
    
    for (int i = 0; i<numsSize; i++)
    {
        int targetDiff = target - nums[i];
        HashTableNode *node = hashTableFindValueWithFilter(mapArray, targetDiff, i);
        
        if (node == NULL)
        {
            continue;
        }
        
        result[0] = i;
        result[1] = node->indexOfValue;
        
        if (result[0] > result[1])
        {
            swap(&(result[0]), &(result[1]));
        }
        
        break;
        
    }

    printf("result[0]:%d, result[1]:%d\n",result[0], result[1]);
    return result;
}


int main(int argc, char ** argv)
{
    int input1[3] = {2,7,5};
    int input2[3] = {4,3,8};

    
    int *result = twoSum(input1, 3, 9);
    
    return 0;
}

