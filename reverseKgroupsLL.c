#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node_t{
    int32_t data;
    struct Node_t *next;
}Node;

typedef enum{SUCCESS = 0, FAIL}rt;


/* reversing groups of k nodes irrespective of the 
last group being a multiple of k or not */

rt reverseKgroups(Node **head, int32_t k){

    if(!head || k <= 1)
        return FAIL;

    /* dummy node simplifies stitching — avoids special-casing the real head */
    Node dummy = {0, NULL};
    Node *tail = &dummy;  /* tracks the tail of the last reversed group */
    Node *groupHead = NULL;
    Node *groupTail = NULL;
    int32_t counter = 0;
    Node *current = *head;
    Node *next = NULL;
    Node *prev = NULL;

    while(1){

        /* before reversing, current is the first node — it will become the group tail */
        groupTail = current;
        prev = NULL;  /* reset so first node in group points to NULL after reversal */
        counter = 0;

        /* standard in-place reversal: redirect each node's next to its predecessor */
        while(current && counter < k){
            next = current->next;   /* save next before overwriting */
            current->next = prev;   /* reverse the link */
            prev = current;
            current = next;
            counter++;
        }
        /* after reversal, prev is the new head of the reversed group */
        groupHead = prev;

        /* stitch: previous group's tail -> this group's head */
        tail->next = groupHead;
        /* advance tail to this group's tail (ready for next iteration) */
        tail = groupTail;

        if(!current){
            break;
        }
    }
    *head = dummy.next;
    return SUCCESS;
}


/* reversing groups of k nodes and leaving the last 
few nodes as is if not a multiple of k */

rt reverseKgroupsExact(Node **head, int32_t k){

    if(!head || k <= 1)
        return FAIL;

    Node dummy = {0, NULL};
    Node *tail = &dummy;
    Node *groupTail = NULL;
    Node *groupHead = NULL;
    int32_t counter = 0;
    Node *current = *head;
    Node *next = NULL;
    Node *prev = NULL;

    while(1){

        /* count ahead to check if k nodes remain */
        Node *check = current;
        counter = 0;
        while(check && counter < k){
            check = check->next;
            counter++;
        }

        /* fewer than k nodes left — link them as-is and stop */
        if(counter < k){
            tail->next = current;
            break;
        }

        /* reverse the group of k */
        groupTail = current;
        prev = NULL;
        counter = 0;

        while(current && counter < k){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            counter++;
        }
        groupHead = prev;

        tail->next = groupHead;
        tail = groupTail;

        if(!current){
            break;
        }
    }
    *head = dummy.next;
    return SUCCESS;
}
