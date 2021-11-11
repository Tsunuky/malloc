/*
** EPITECH PROJECT, 2019
** malloc.c
** File description:
** malloc
*/

#include "malloc.h"

static void *global_base = NULL;

struct node *find_block(struct node **last, size_t size)
{
    struct node *current = global_base;

    while (current && !(current->free && current->size >= size)) {
        *last = current;
        current = current->next;
    }
    return (current);
}

struct node *need_space(struct node *last, size_t size)
{
    struct node *new_node = sbrk(0);
    void *need = sbrk(size + SIZE_NODE);

    if (need == (void *) -1)
        return NULL;
    if (last)
        last->next = new_node;
    new_node->size = size;
    new_node->next = NULL;
    new_node->free = 0;
    return (new_node);
}

struct node *get_block(void *ptr)
{
    return ((struct node *) ptr - 1);
}

void *malloc(size_t size)
{
    struct node *new_node;

    if (size > (SIZE_MAX - size))
        return NULL;
    if (!global_base) {
        new_node = need_space(NULL, size);
        if (!new_node)
            return (NULL);
        global_base = new_node;
    } else {
        struct node *last = global_base;
        new_node = find_block(&last, size);
        if (!new_node) {
            new_node = need_space(last, size);
            if (!new_node)
                return (NULL);
        } else
            new_node->free = 1;
    }
    return (new_node + 1);
}
