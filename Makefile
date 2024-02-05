CC = clang
NAME = pipex
LIBFT = libft/libft.a
SRCS_BONUS = srcs_bonus/pipex_bonus.c \
				srcs_bonus/here_doc_bonus.c \
				srcs_bonus/free_bonus.c \
				srcs_bonus/cmd_pipes_bonus.c
SRCS = srcs/pipex.c \
		srcs/free.c \
		srcs/cmd_pipes.c
HEADER = pipex.h, pipex_bonus.h
OBJS = $(SRCS:.c=.o)
OBJS_BNS = $(SRCS_BONUS:.c=.o)
CFLAGS = -Werror -Wextra -Wall -g

all:$(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)
	@printf "\033[1;32mCompilation Finished!\n\033[0m"

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@printf "\033[1;35mFiles Deleted!\n\033[0m"

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_BNS)
	@make --no-print-directory -C libft/ clean
	@printf "\033[1;35mObjects Deleted!\n\033[0m"

bonus: $(OBJS_BNS) $(LIBFT)
	@$(CC) $(SRCS_BONUS) $(LIBFT) -o $(NAME)
	@printf "\033[1;32mBonus compilation Finished!\n\033[0m"

$(LIBFT):
	@make --no-print-directory -C libft/ all
	@printf "\033[1;32mLibft compilation Finished !\n\033[0m"
	@make --no-print-directory -C libft/ bonus

re: fclean all

.PHONY: all fclean clean re bonus