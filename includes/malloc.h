/*
** EPITECH PROJECT, 2019
** malloc.h
** File description:
** malloc
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

void *malloc(size_t);
void *realloc(void *, size_t);
void free(void *);

#define SIZE_NODE sizeof(struct node)

struct node {
    size_t size;
    struct node *next;
    int free;
};

struct node *find_block(struct node **, size_t);
struct node *nedd_space(struct node *, size_t);
struct node *get_block(void *);

#endif
