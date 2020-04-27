# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/25 20:20:38 by florianhame       #+#    #+#              #
#    Updated: 2020/04/26 16:54:37 by florianhame      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

MINI_RT		=	mini_rt

D_INCLUDES	=	includes/

D_OBJS		=	objs/

D_SRCS		=	srcs/

_SRC_		=	check_objs.c \
				check_test.c \
				check_utils.c \
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
				get_next_line.c \
				get_next_line_utils.c \
				intersections.c \
				intersections_utils.c \
				main_test.c \
				parsing.c \
				parsing2.c \
				ray_tracer.c \
				ray_tracer_utils.c \
				scene.c

SRCS		=	$(addprefix $(D_SRCS), $(_SRC_))
OBJS		=	$(addprefix $(D_OBJS), $(_SRC_:.c=.o))
FT_PRINTF	=	libftprintf.a
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

$(MLX) : FORCE
	@make -C mlx 

$(D_OBJS)%.o : $(D_SRCS)%.c
	$(CC) $(FLAGS) -c $< -o $@ -Iincludes -Ift_printf -Imlx

$(MINI_RT) : $(FT_PRINTF) $(MLX) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -framework OpenGL -framework Appkit -o $@ \
	-Iincludes -Ift_printf -Lft_printf -lftprintf -Lmlx -lmlx

clean :
	@rm -rf $(D_OBJS)
	@make clean -C ft_printf
	@make clean -C mlx


fclean : clean
	@rm -rf $(MINI_RT)
	@make fclean -C ft_printf
	@make clean -C mlx

re : fclean all

FORCE :