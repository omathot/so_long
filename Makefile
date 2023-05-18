# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 01:41:47 by oscarmathot       #+#    #+#              #
#    Updated: 2023/04/19 00:17:54 by oscarmathot      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------
#VARIABLES

NAME 	:= so_long
SRC 	:= map_validation.c free_help.c fit_map.c map_struct.c map_filling.c \
			movement_helper.c hook.c main.c window.c extra_validation.c
OBJ 	:= $(SRC:.c=.o)
LIBFT_A	:= lib/libft/libft.a
PRINTF_A := lib/printf/libftprintf.a
MLX42_A	:= lib/MLX42/build/libmlx42.a
CMP		:= gcc
FLAGS 	:= -Werror -Wall -Wextra -g -I lib
OS 		:= $(shell uname -m)


#---------------------------------
#OS CHECK

ifeq ($(OS), arm64)
	OSFLAGS = -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"
else ifeq ($(OS), x86_64)
	OSFLAGS	= -lglfw -L"/Users/omathot/.brew/opt/glfw/lib/"
else
	$(error Unsupported architecture: $(OS))
endif

#---------------------------------
#FORMATTING AND FUN

clear_line = \033[K
move_up = \033[A
define prettycomp
	@printf "$(1)$(clear_line)\n"
	@$(1)
	@printf "$(move_up)"
endef

RED		:= \033[31m
GREEN 	:= \033[32m
YELLOW	:= \033[33m
BLUE	:= \033[38;5;87m
MAGENTA := \033[35m
CYAN	:= \033[36m
RESET	:= \033[0m

#---------------------------------
#RULES

all	: $(NAME)
		@echo "$(GREEN)Project built successfully !$(RESET)"
		@echo "$(BLUE)Usage: so_long <path to map>$(RESET)"

$(NAME) : $(OBJ) $(LIBFT_A) $(PRINTF_A) $(MLX42_A) so_long.h
		@echo "$(CYAN)Creating the executable...$(RESET)"
		@$(CC) $(FLAGS) $(OSFLAGS) $(OBJ) $(LIBFT_A) $(PRINTF_A) $(MLX42_A) -o $(NAME)

%.o : %.c so_long.h
		@echo "$(CYAN)Compiling...$(RESET) $<"
		$(call prettycomp, $(CMP) -c $(FLAGS) -o $@ $<)

$(LIBFT_A) : 
		@echo "$(BLUE)Building libft library...$(RESET)\n"
		$(call prettycomp, @make -C lib/libft)

$(PRINTF_A) :
		@echo "$(BLUE)Building ft_printf library...$(RESET)\n"
		$(call prettycomp, @make -C lib/printf)
	
$(MLX42_A) :
		@echo "$(YELLOW)Building MLX42 library...$(RESET)"
		(cd ./lib/MLX42 && cmake -B build)
		(cd ./lib/MLX42 && cmake --build build -j4)

clean :
		@rm -f $(OBJ) ./lib/libft/libft.a
		@echo "$(GREEN)Cleaned up the artifacts !$(RESET)"

fclean :
		@rm -f $(NAME) $(OBJ)
		@echo "$(MAGENTA)Cleaned up executable !$(RESET)"

hardclean : 
		@make fclean
		cd ./lib/libft && make clean
		cd ./lib/libft && make fclean
		cd ./lib/MLX42 && rm -rf build
		cd ./lib/printf && make clean
		cd ./lib/printf && make fclean
		@echo "$(MAGENTA)Cleaned up all built files!$(RESET)"

re : fclean all
	
.PHONY : clean fclean re hardclean