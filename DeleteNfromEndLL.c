#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Node_t{
    uint32_t data;
    struct Node_t *next;
}Node;

typedef enum{SUCCESS = 0, FAIL}rt;

rt removeNfromEnd(Node *head, int32_t pos){
    
    Node dummy = {0, NULL};

    Node *slow = &dummy;
    dummy.next = head;
    Node *fast = head;

    int32_t counter = 1;
    while(fast->next && counter != pos - 1){
        fast = fast->next;
        counter++;
    }
    counter = 1;
    while(fast && counter != pos - 1){
        slow = slow->next;
        fast = fast->next;
        counter++;
    }
    Node *victim = slow->next;
    slow->next = victim->next;
    free(victim);
    victim = NULL;
    return SUCCESS;
}