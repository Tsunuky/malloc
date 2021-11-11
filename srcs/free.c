/*
** EPITECH PROJECT, 2019
** free.c
** File description:
** malloc
*/

#include "malloc.h"

struct node *get_block_ptr(void *ptr)
{
    return (struct node *)ptr - 1;
}

void free(void *ptr)
{
    if (!ptr)
        return;
    struct node *delete_node = get_block_ptr(ptr);
    delete_node->free = 1;
}
