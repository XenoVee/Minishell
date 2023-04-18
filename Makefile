# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile-Program                                   :+:    :+:             #
#                                                      +:+                     #
#    By: rmaes <rmaes@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/13 17:19:52 by rmaes         #+#    #+#                  #
#    Updated: 2023/04/18 17:16:52 by rmaes         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


#Colors

DEFAULT = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m

SOURCES_DIR = sources/
FILES =	
SOURCES = $(addprefix $(SOURCES_DIR), $(FILES))

OBJECTS_DIR = objects/
OBJECTS = $(addprefix $(OBJECTS_DIR), $(FILES:.c=.o))

CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = 

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "compiling: $(YELLOW)creating executable$(DEFAULT)"
	@$(CC) -o $@ $^
	@echo "$(GREEN)$@ successfully compiled!$(DEFAULT)"

$(OBJECTS_DIR):
	mkdir objects

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	@mkdir -p $(@D)
	@echo "compiling: $(YELLOW)$@$(DEFAULT)"
	@$(CC) -c $(CFLAGS) -o $@ $^

clean:
	@echo "cleaning:  $(RED)removing object files$(DEFAULT)"
	@rm -f $(OBJECTS)

fclean: clean
	@echo "cleaning:  $(RED)removing $(NAME)$(DEFAULT)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re