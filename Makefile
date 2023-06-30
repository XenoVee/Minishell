# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rmaes <rmaes@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/13 17:19:52 by rmaes         #+#    #+#                  #
#    Updated: 2023/06/30 17:07:42 by Owen          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


#Colors

DEFAULT = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m

#main files
MAIN_FILES = main.c 
MAIN_FILES = main.c 
MAIN_DIR = main/
MAIN_DF = $(addprefix $(MAIN_DIR), $(MAIN_FILES))

#utils files
UTILS_FILES = 		cleanup.c\
					error.c\
					init_data.c
UTILS_DIR = utils/
UTILS_DF = $(addprefix $(UTILS_DIR), $(UTILS_FILES))

#tokenizer files
LEXER_FILES = 		check_for_var.c\
					parse_input_str.c\
					token_list.c\
					tokenizer_utils.c\
					tokenizer.c
LEXER_DIR = lexer/
LEXER_DF = $(addprefix $(LEXER_DIR), $(LEXER_FILES))

#expander files
EXPANDER_FILES =	expand_get_string.c\
					expand_utils.c\
					expand_utils2.c\
					expand_var.c\
					quotes_utils.c\
					quotes.c
EXPANDER_DIR = expansion/
EXPANDER_DF = $(addprefix $(EXPANDER_DIR), $(EXPANDER_FILES))

#parsing files
PARSING_FILES =		cmd_list.c\
					cmd_list_utils.c\
					heredoc_utils.c\
					heredoc_utils2.c\
					parse_heredoc.c\
					parse_input.c\
					parse_trunc.c\
					parse_append.c\
					parse_words.c\
					parse_data.c\
					process_add_echo.c\
					process_create_echo.c\
					process_args.c
PARSING_DIR = parsing/
PARSING_DF = $(addprefix $(PARSING_DIR), $(PARSING_FILES))

#signal files
SIGNAL_FILES =		loop.c\
					signals.c
SIGNAL_DIR = signals/
SIGNALS_DF = $(addprefix $(SIGNAL_DIR), $(SIGNAL_FILES))

#environment variables files
ENVP_FILES = envp.c ft_getenv.c
ENVP_DIR = envp/
ENVP_DF = $(addprefix $(ENVP_DIR), $(ENVP_FILES))

#builtins
BUILTIN_FILES = echo.c env.c unset.c export.c pwd.c cd.c exit.c
BUILTIN_DIR = builtins/
BUILTIN_DF = $(addprefix $(BUILTIN_DIR), $(BUILTIN_FILES))

#executor files
EXECUTOR_FILES = $(BUILTIN_DF) executor.c pathfinder.c
EXECUTOR_DIR = executor/
EXECUTOR_DF = $(addprefix $(EXECUTOR_DIR), $(EXECUTOR_FILES))

ENDING_FILES = exit.c
ENDING_DIR = ending/
ENDING_DF =$(addprefix $(ENDING_DIR), $(ENDING_FILES))

SOURCES_DIR = sources/
FILES =	$(MAIN_DF) $(LEXER_DF) $(EXPANDER_DF) $(PARSING_DF) $(UTILS_DF) $(SIGNALS_DF) $(ENVP_DF) $(ENDING_DF)
#FILES =	$(MAIN_DF) $(LEXER_DF) $(EXPANDER_DF) $(PARSING_DF) $(EXECUTOR_DF) $(UTILS_DF) $(SIGNALS_DF) $(ENVP_DF) $(ENDING_DF)
SOURCES = $(addprefix $(SOURCES_DIR), $(FILES))

#INCLUDES = includes -I/Users/rmaes/.brew/opt/readline/include
MAC_INCLUDES = includes -I/opt/homebrew/opt/readline/include

OBJECTS_DIR = objects/
OBJECTS = $(addprefix $(OBJECTS_DIR), $(FILES:.c=.o))

CFLAGS = -Wall -Wextra -Werror
CC = gcc -g
NAME = minishell

LIBFT_FOLDER = libraries/libftprintf/
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_FOLDER), $(LIBFT_NAME))

LIST_FOLDER = libraries/cdl_list/
LIST_NAME = cdl_list.a
LIST = $(addprefix $(LIST_FOLDER), $(LIST_NAME))

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(LIST)
	@echo "compiling: $(YELLOW)creating executable$(DEFAULT)"
	@$(CC) -o $@ $^ -lreadline -L/opt/homebrew/opt/readline/lib
#	@$(CC) -o $@ $^ -lreadline -L/Users/rmaes/.brew/opt/readline/lib
	@echo "$(GREEN)$@ successfully compiled!$(DEFAULT)"

$(OBJECTS_DIR):
	@mkdir objects

$(LIBFT):
	@make -C $(LIBFT_FOLDER)

$(LIST):
	@make -C $(LIST_FOLDER)

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c 
	@mkdir -p $(@D)
	@echo "compiling: $(YELLOW)$@$(DEFAULT)"
	@$(CC) -c $(CFLAGS) -I $(MAC_INCLUDES) -o $@ $^

clean:
	@echo "cleaning:  $(RED)removing object files$(DEFAULT)"
	@rm -f $(OBJECTS)
	@rm -rf $(OBJECTS_DIR)
	@make -C $(LIBFT_FOLDER) clean
	@make -C $(LIST_FOLDER) clean

fclean: clean
	@echo "cleaning:  $(RED)removing $(NAME)$(DEFAULT)"
	@rm -f $(NAME)
	@make -C $(LIBFT_FOLDER) rmlib
	@make -C $(LIST_FOLDER) rmlib

re: fclean all

.PHONY: all clean fclean re