# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rmaes <rmaes@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/13 17:19:52 by rmaes         #+#    #+#                  #
#    Updated: 2023/06/15 14:39:56 by ohearn        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


#Colors

DEFAULT = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m

#main files
MAIN_FILES = main.c error.c
MAIN_DIR = main/
MAIN_DF = $(addprefix $(MAIN_DIR), $(MAIN_FILES))

#lexer files
LEXER_FILES = 	string.c\
				tokenizer_utils.c\
				tokenizer.c
LEXER_DIR = lexer/
LEXER_DF = $(addprefix $(LEXER_DIR), $(LEXER_FILES))

#signal files
SIGNALS_FILES = signals.c
SIGNALS_DIR = signals/
SIGNALS_DF = $(addprefix $(SIGNALS_DIR), $(SIGNALS_FILES))

#utils files
UTILS_FILES = 	init_data.c
UTILS_DIR = utils/
UTILS_DF = $(addprefix $(UTILS_DIR), $(UTILS_FILES))


#builtins
BUILTIN_FILES = echo.c env.c
BUILTIN_DIR = builtins/
BUILTIN_DF = $(addprefix $(BUILTIN_DIR), $(BUILTIN_FILES))

#builtins
BUILTIN_FILES = echo.c env.c unset.c exit.c
BUILTIN_DIR = builtins/
BUILTIN_DF = $(addprefix $(BUILTIN_DIR), $(BUILTIN_FILES))
#executor files
EXECUTOR_FILES = $(BUILTIN_DF) executor.c pathfinder.c expansion.c 
EXECUTOR_DIR = executor/
EXECUTOR_DF = $(addprefix $(EXECUTOR_DIR), $(EXECUTOR_FILES))


SOURCES_DIR = sources/
FILES =	$(MAIN_DF) $(LEXER_DF) $(UTILS_DF) $(SIGNALS_DF)
SOURCES = $(addprefix $(SOURCES_DIR), $(FILES))

INCLUDES = includes

OBJECTS_DIR = objects/
OBJECTS = $(addprefix $(OBJECTS_DIR), $(FILES:.c=.o))

CFLAGS = -Wall -Wextra -Werror
CC = gcc -g
NAME = minishell

LIBFT_FOLDER = libraries/libftprintf/
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_FOLDER), $(LIBFT_NAME))

LIST_FOLDER = libraries/dl_list/
LIST_NAME = dl_list.a
LIST = $(addprefix $(LIST_FOLDER), $(LIST_NAME))

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(LIST)
	@echo "compiling: $(YELLOW)creating executable$(DEFAULT)"
	@$(CC) -o $@ $^ -l readline
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
	@$(CC) -c $(CFLAGS) -I $(INCLUDES) -o $@ $^

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