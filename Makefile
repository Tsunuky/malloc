##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## malloc
##

CC			=			gcc
RM			=			rm -rvf

OUT			=			libmy_malloc.so

SRCS			=			./srcs/malloc.c					\
						./srcs/realloc.c				\
						./srcs/free.c					\

CFLAGS			=			-I./includes -W -Wall -Wextra -O2 -fPIC -std=gnu99
LDFLAGS			=			-shared

OBJS			=			$(SRCS:.c=.o)

all : $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(OUT)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(OUT)

re : fclean all

.PHONY : all clean fclean re
