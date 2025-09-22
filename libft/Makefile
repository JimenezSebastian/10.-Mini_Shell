# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almejia- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/13 22:08:57 by almejia-          #+#    #+#              #
#    Updated: 2024/05/05 08:58:06 by almejia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIB = ar rcs
RM = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

SRC =  src/ft_atoi.c src/ft_bzero.c src/ft_calloc.c src/ft_isalnum.c \
       src/ft_isalpha.c src/ft_isascii.c src/ft_isdigit.c src/ft_isprint.c \
       src/ft_itoa.c src/ft_memchr.c src/ft_memcmp.c src/ft_memcpy.c \
       src/ft_memmove.c src/ft_memset.c src/ft_putchar_fd.c src/ft_putendl_fd.c \
       src/ft_putnbr_fd.c src/ft_putstr_fd.c src/ft_split.c src/ft_strcat.c \
       src/ft_strchr.c src/ft_strdup.c src/ft_striteri.c src/ft_strjoin.c \
       src/ft_strlcat.c src/ft_strlcpy.c src/ft_strlen.c src/ft_strmapi.c \
       src/ft_strncmp.c src/ft_strnstr.c src/ft_strrchr.c src/ft_strtrim.c \
       src/ft_substr.c src/ft_tolower.c src/ft_toupper.c

BONUSsRC = src/ft_lstadd_back_bonus.c src/ft_lstadd_front_bonus.c \
           src/ft_lstclear_bonus.c src/ft_lstdelone_bonus.c \
           src/ft_lstiter_bonus.c src/ft_lstlast_bonus.c \
           src/ft_lstmap_bonus.c src/ft_lstnew_bonus.c src/ft_lstsize_bonus.c

OBJ = $(SRC:.c=.o)
BONUSOBJ = $(BONUSSRC:.c=.o)

INCLUDE = include/libft.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUSOBJ) $(INCLUDE)
	$(LIB) $(NAME) $(BONUSOBJ) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ) $(BONUSOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus
