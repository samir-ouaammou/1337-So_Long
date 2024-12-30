# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souaammo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 11:42:39 by souaammo          #+#    #+#              #
#    Updated: 2024/12/30 11:42:41 by souaammo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = so_long.c so_long_utils1.c so_long_utils2.c so_long_utils3.c so_long_utils4.c \
        so_long_utils5.c so_long_utils6.c get_next_line.c get_next_line_utils.c

BFILES = so_long_bonus.c so_long_utils1_bonus.c so_long_utils2_bonus.c so_long_utils3_bonus.c \
         so_long_utils4_bonus.c so_long_utils5_bonus.c so_long_utils6_bonus.c so_long_utils7_bonus.c \
         so_long_utils8_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = $(FILES:.c=.o)

BOBJS = $(BFILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBS = -lmlx -lXext -lX11

NAME = so_long

RM = rm -rf

all: $(NAME)

bonus: $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) $(LIBS) -o $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
