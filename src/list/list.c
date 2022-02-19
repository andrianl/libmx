#include "list.h"

list *create_node(void *data)
{
    list *node = (list *)malloc(sizeof(list));

    node->data = data;
    node->next = NULL;

    return node;
}

list *sort_list(list *node, bool (*cmp)(void *, void *))
{
    list *temp;
    list *buff = node;
    int list_len = list_size(buff);

    for (int i = list_len - 1; i > 0; i--)
    {
        buff = node;
        for (int j = 0; j < i; j++)
        {
            if (cmp(buff->data, buff->next->data) == true)
            {
                temp = buff->data;
                buff->data = buff->next->data;
                buff->next->data = temp;
            }
            buff = buff->next;
        }
    }
    return node;
}

void pop_back(list **node)
{

    if (node == NULL || *node == NULL)
        return;

    list *temp = *node;

    if (temp->next == NULL)
    {
        free(*node);
        *node = NULL;
        return;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void pop_front(list **node)
{
    if (node == NULL || *node == NULL)
        return;

    list *temp = *node;
    *node = temp->next;
    free(temp);
    temp = NULL;
}

void push_back(list **node, void *data)
{
    list *new_tail = create_node(data);
    list *temp = *node;

    if (*node == NULL)
    {
        *node = new_tail;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_tail;
}

void push_front(list **node, void *data)
{
    list *new_head = create_node(data);

    new_head->next = *node;
    *node = new_head;
}

void swap_node(void **s1, void **s2)
{
    void *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int list_size(list *node)
{
    int result = 0;

    while (node != NULL)
    {
        result++;
        node = node->next;
    }

    return result;
}
