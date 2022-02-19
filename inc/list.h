#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct list
{
    void *data;
    struct list *next;
} list;

list *create_node(void *data);
list *sort_list(list *node, bool (*cmp)(void *, void *));
void pop_back(list **node);
void pop_front(list **node);
void push_back(list **node, void *data);
void push_front(list **node, void *data);
void swap_node(void **s1, void **s2);
int list_size(list *node);
