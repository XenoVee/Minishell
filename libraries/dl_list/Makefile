# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ohearn <ohearn@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/04 16:23:53 by ohearn        #+#    #+#                  #
#    Updated: 2023/05/09 17:26:18 by ohearn        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#Colors
DEFAULT = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m

SOURCES_DIR = sources/
FILES =		dl_list_utils.c\
			dl_create_list.c\
			dl_newnode.c\
			dl_list_add_back.c\
			dl_list_clear.c\
			dl_list_iter.c\


SOURCES = $(addprefix $(SOURCES_DIR), $(FILES))
OBJECTS_DIR = objects/
OBJECTS = $(addprefix $(OBJECTS_DIR), $(FILES:.c=.o))

CFLAGS = -Wall -Wextra -Werror -g
CC = gcc
NAME = dl_list.a

all: $(OBJECTS_DIR) $(NAME) 

$(NAME): $(OBJECTS) 
	@echo "compiling: $(YELLOW)creating library$(DEFAULT)"
	@ar -rcsu $@ $^
	@echo "$(GREEN)$@ successfully compiled!$(DEFAULT)"

$(OBJECTS_DIR):
	@mkdir objects

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	@echo "compiling: $(YELLOW)$@$(DEFAULT)"
	@$(CC) -c $(CFLAGS) -o $@ $^

clean:
	@echo "cleaning:  $(RED)removing $(NAME) object files$(DEFAULT)"
	@rm -f $(OBJECTS)
	@rm -rf $(OBJECTS_DIR)

rmlib:
	@echo "cleaning:  $(RED)removing $(NAME)$(DEFAULT)"
	@rm -f $(NAME)

fclean: clean rmlib
	

re: fclean all

.PHONY: all clean fclean re bonus
