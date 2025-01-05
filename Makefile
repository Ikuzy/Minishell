# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/05 18:32:39 by ozouine           #+#    #+#              #
#    Updated: 2025/01/05 21:56:08 by ozouine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror  #-g3 -fsanitize=address
READLINE = -lreadline
LIBFT = libft/libft.a
SRC =	minishell.c \
		GNL/get_next_line_utils.c \
		GNL/get_next_line.c \
		GNL/utils.c \
		src_fls/execution/built_in.c \
		src_fls/execution/cd.c \
		src_fls/execution/check_cmd_access.c \
		src_fls/execution/echo.c \
		src_fls/execution/env_utils.c \
		src_fls/execution/env.c \
		src_fls/execution/execute_child.c \
		src_fls/execution/execute_utils.c \
		src_fls/execution/execution.c \
		src_fls/execution/export_utils.c \
		src_fls/execution/export.c \
		src_fls/execution/free_utils.c \
		src_fls/execution/ft_free.c \
		src_fls/execution/heredoc.c \
		src_fls/execution/init_mini.c \
		src_fls/execution/print_lst.c \
		src_fls/execution/replace_struct.c \
		src_fls/execution/signal.c \
		src_fls/execution/stp_dup.c \
		src_fls/execution/str_utils.c \
		src_fls/execution/unset.c \
		src_fls/parsing/ambigeous.c \
		src_fls/parsing/free.c \
		src_fls/parsing/get_types.c \
		src_fls/parsing/line.c \
		src_fls/parsing/parse_args.c \
		src_fls/parsing/parse.c \
		src_fls/parsing/split_token.c \
		src_fls/parsing/split.c \
		src_fls/parsing/syntax.c \
		src_fls/parsing/token_utils.c \
		src_fls/parsing/token_utils2.c \
		src_fls/parsing/token.c \
		src_fls/expend/emty_cmd_args.c \
		src_fls/expend/expand_var.c \
		src_fls/expend/expension.c \
		src_fls/expend/heredoc.c \
		src_fls/expend/quotes.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(READLINE) $(CFLAGS) $(LIBFT) -o $(NAME)

$(LIBFT) :
	make -sC ./libft all

clean :
	rm -rf $(OBJ)
	make -sC libft clean
fclean : clean
	rm -rf $(NAME)
	make -sC libft fclean
re : fclean all
.SECONDARY: $(OBJ)
.PHONY: all, clean, fclean, re
