# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 11:42:39 by souaammo          #+#    #+#              #
#    Updated: 2025/01/03 20:09:56 by souaammo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = so_long.c so_long_utils1.c so_long_utils2.c so_long_utils3.c so_long_utils4.c	so_long_utils5.c\
        so_long_utils6.c	so_long_utils7.c	so_long_utils8.c	 get_next_line.c get_next_line_utils.c

OBJS = $(FILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBS = -lmlx -lXext -lX11

NAME = so_long

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
