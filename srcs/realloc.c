/*
** EPITECH PROJECT, 2019
** realloc.c
** File description:
** malloc
*/

#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
    void *new_ptr;
    struct node *new_node;

    if (!ptr)
        return (malloc(size));
    if (size == 0) {
        free(ptr);
        return (NULL);
    }
    new_node = get_block(ptr);
    if (new_node->size >= size)
        return (ptr);
    new_ptr = malloc(size);
    if (!new_ptr)
        return (NULL);
    memcpy(new_ptr, ptr, new_node->size);
    free(ptr);
    return (new_ptr);
}
