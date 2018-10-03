#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int val;
    struct node * next;
} node_t;


void listAdd(const node_t * head, int val) 
{
    node_t * current = head;
    while (current->next != NULL) 
    {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

void listPrint(const node_t * head) 
{
    node_t * current = head;

    while (current != NULL) 
    {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int listRemoveLast(node_t * head) {
    int retval = 0;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL) 
    {
        retval = head->val;
        free(head);
        return retval;
    }

    /* get to the second to last node in the list */
    node_t * current = head;
    while (current->next->next != NULL) 
    {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;
}

int listIs(const node_t * head, int n) 
{
    node_t * current = head;
    int retval = -1;
    
    if (head == NULL) 
    {
        return -1;
    }

    if (n == 0) 
    {
        return current->val;
    }

    for (int i = 0; i <= n-1; ++i) 
    {
        if (current->next == NULL) 
        {
            return -1;
        }
        retval  = current->next->val;
        current = current->next;
    }
    return retval;
}

int listRemove(node_t ** head)
{
    node_t * next_node = NULL;

    if (*head == NULL) 
    {
        return -1;
    }

    while(*head != NULL)
    {
        next_node = (*head)->next;
        free(*head);
        *head = next_node;
    }

    return 0;
}

int main()
{
    node_t * list = NULL;
    
    list = malloc(sizeof(node_t));
    list->val = 15;
    list->next = NULL;
    listAdd(list, 20);
    listAdd(list, 30);
    listAdd(list, 40);
    listPrint(list);
    printf("listIs[3] = %d\n", listIs(list, 3));
    listRemoveLast(list);
    printf("listIs[3] = %d\n", listIs(list, 3));
    listAdd(list, 50);
    printf("removeList = %d\n", listRemove(&list));
    listPrint(list);

    return 0;
}