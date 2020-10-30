# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/25 20:20:38 by florianhame       #+#    #+#              #
#    Updated: 2020/10/30 02:12:24 by fhamel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

MINI_RT		=	miniRT

D_INCLUDES	=	includes/

D_OBJS		=	objs/

D_SRCS		=	srcs/

_SRC_		=	block.c \
				check_objs.c \
				check_objs2.c \
				check_test.c \
				check_utils.c \
				check_utils2.c \
				color.c \
				data.c \
				data_abc.c \
				data_abc2.c \
				data_append.c \
				data_append2.c \
				data_objs.c \
				data_objs2.c \
				data_utils.c \
				data_utils2.c \
				facing_ratio.c \
				facing_ratio2.c \
				get_next_line.c \
				get_next_line_utils.c \
				intersection.c \
				intersection_utils.c \
				intersection_utils2.c \
				intersection_utils3.c \
				light_intersection.c \
				main.c \
				objs_scene.c \
				parsing.c \
				parsing2.c \
				ray_tracer.c \
				ray_tracer_utils.c \
				reflexion.c \
				save.c \
				screen.c \
				screen_utils.c

SRCS		=	$(addprefix $(D_SRCS), $(_SRC_))
OBJS		=	$(addprefix $(D_OBJS), $(_SRC_:.c=.o))
FT_PRINTF	=	libftprintf.a
APPS		=	-framework OpenGL -framework Appkit
MLX_DIR		=	mlx_macos/

OS			:= $(shell uname)

ifeq	($(OS), Linux)
	MLX_DIR	=	mlx_linux/
	APPS	=	-lm -lXext -lX11
	_SRC_ 	+=	scene_linux.c
endif

ifeq	($(OS), Darwin)
	_SRC_	+= scene_macos.c
endif

MLX			=	libmlx.a

################################################################################
#####                           COMPILER OPTIONS                           #####
################################################################################

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
FSANITIZE	=	-g -fsanitize=address

################################################################################
#####                            MAKEFILE RULES                            #####
################################################################################

.PHONY : all clean fclean re

all	: $(D_OBJS) $(MINI_RT)

$(D_OBJS) :
	@mkdir -p $@

$(FT_PRINTF) : FORCE
	@make -C ft_printf

$(D_OBJS)%.o : $(D_SRCS)%.c
	$(CC) $(FLAGS) -c $< -o $@ -Iincludes -Ift_printf -Imlx

$(MINI_RT) : $(FT_PRINTF) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(APPS) -Iincludes -Ift_printf -Lft_printf -lftprintf -L$(MLX_DIR) -lmlx -o $@

clean :
	@rm -rf $(D_OBJS)
	@make clean -C ft_printf

fclean : clean
	@rm -rf $(MINI_RT)
	@make fclean -C ft_printf

re : fclean all

FORCE :