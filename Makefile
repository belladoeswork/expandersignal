NAME		:= lumumbash

CC			:= cc

CFLAGS		:= -Wall -Werror -Wextra

BUILTINS	:=	builtins/echo.c \
				builtins/exit.c \
				builtins/pwd.c \
				builtins/export.c \
				builtins/unset.c \
#				builtins/env.c \

CLEANERS	:=	cleaners/clean.c \
				cleaners/free.c \
				cleaners/clear.c \

EXEC		:=	exec/checks.c \
				exec/errors.c \
				exec/exec_redir.c \
				exec/exec_simple.c \
				exec/exec_utils.c \
				exec/exec.c \
				exec/pipes_exec.c \
				exec/tree.c \
				exec/signals.c \

EXPANDER    :=  expander/expander.c \
                expander/create_env_lists.c \
                expander/ft_frees.c \
                expander/new_ft_split.c \
                expander/tester_functions.c \
                expander/ft_split_double.c \
                expander/ft_split_bis.c \
                expander/expander_utils.c \
                expander/expand_assemble.c \
                expander/remove_wrong_env_var.c \
                expander/expand_tilde.c \


HELP		:=  help/helpers.c \
				help/exphelp.c \
				help/libfthelp.c \
				help/tk_helpers.c \
				help/libfthelpers.c \

PARSER		:=	parser/nodes.c \
				parser/parser_errors.c \
				parser/parser_helpers.c \
				parser/parser_utils.c \
				parser/parser.c \

TOKENIZER	:=	tokenizer/tokenizer.c \
				tokenizer/handlers.c \
				tokenizer/tokens_list.c \
				tokenizer/tokens_utils.c \
				tokenizer/tokenizer_utils.c \

SRCS		:=	$(BUILTINS)\
				$(HELP)\
				$(CLEANERS)\
				$(EXEC)\
				$(EXPANDER)\
				$(PARSER)\
				$(TOKENIZER)\
				main.c

OBJS		:=	$(SRCS:.c=.o)

READLINE_PATH:=	/goinfre/homebrew/opt/readline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -Iincludes -I$(READLINE_PATH)/include

all: $(NAME)


$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) -L$(READLINE_PATH)/lib -lreadline

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
