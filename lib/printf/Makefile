# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 23:06:58 by oscarmathot       #+#    #+#              #
#    Updated: 2023/04/19 00:10:14 by oscarmathot      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clear_line = \033[K
move_up = \033[A
define prettycomp
	@printf "$(1)$(clear_line)\n"
	@$(1)
	@printf "$(move_up)"
endef

NAME = libftprintf.a
SRC = ft_hexa_utils.c ft_pointer.c ft_printf.c ft_unsigned.c ft_utils.c ft_utils_2.c ft_utils_3.c
OBJ = $(SRC:.c=.o)
CMP = gcc
FLAGS = -Werror -Wall -Wextra -I

all : $(NAME)

$(NAME) : $(OBJ)
		@ar rc $@ $^

ft_%.o: ft_%.c
	$(call prettycomp, $(CMP) $(FLAGS) ft_printf.h -c $^)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY = re fclean clean all
