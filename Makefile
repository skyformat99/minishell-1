# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmekwa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/31 11:53:06 by tmekwa            #+#    #+#              #
#    Updated: 2017/08/31 11:53:15 by tmekwa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = minishell

SRC =		sources/ft_execute_command.c				\
		  	sources/ft_get_path.c						\
			sources/ft_launch.c							\
		    sources/minishell.c							\
			sources/ft_cd.c								\
			sources/ft_echo.c							\
			sources/ft_clear.c							\
			sources/ft_enviro.c							\
			sources/ft_array_plus.c					\
			sources/ft_realloc.c						\
			sources/ft_setenv.c							\
			sources/ft_split.c							\
			sources/ft_exit.c							\
		    sources/ft_unsetenv.c						\
			libft/ft_sstrlen.c 							\
			libft/ft_sstrnew.c							\
			get_next_line/get_next_line.c	

HEADER = -I include

LFLAGS = -L./libft/ -lft

FLAGS = -o minishell -Wall -Werror -Wextra

all:
		@make -C libft/
		@gcc $(FLAGS) $(SRC) $(HEADER) $(LFLAGS)

clean:
		@rm $(NAME)
		@make -C libft/ clean

fclean: clean
		@rm -rf $(NAME)
		@rm -rf libft/libft.a

val:
	@valgrind --leak-check=full ./minishell

re: fclean all