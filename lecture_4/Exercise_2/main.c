#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int val;
    struct node * next;
} node_t;


void listPrint(const node_t * head) 
{
    node_t * current = head;

    while (current != NULL) 
    {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void push(node_t ** head, int val) {
    node_t * new_node;
    new_node = malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}


int read(const node_t * head, int n) 
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


int main()
{
    node_t * list = NULL;
    
    list = malloc(sizeof(node_t));
    list->val = 15;
    list->next = NULL;
    push(&list, 20);
    push(&list, 30);
    push(&list, 40);
    listPrint(list);
    printf("listIs[3] = %d\n", read(list, 3));
    
     while (list != NULL) 
    {
        printf("pop = %d\n", pop(&list));
    }
    
    listPrint(list);

    return 0;
}