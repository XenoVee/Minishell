# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rmaes <rmaes@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/13 17:19:52 by rmaes         #+#    #+#                  #
#    Updated: 2023/06/29 15:24:32 by rmaes         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#Colors

DEFAULT = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m

OBJECTS_DIR = objects/
SOURCES_DIR = sources/
PRINTF_DIR = ft_printf/
FPRINTF_DIR = ft_fprintf/
GNL_DIR = get_next_line/

FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_min.c ft_max.c ft_btw.c ft_is_atoi.c ft_abs.c ft_ultoa.c ft_atoul.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_realloc.c \
		ft_digitcount.c ft_digitcount_unsigned.c ft_is_negative.c ft_strcmp.c \
		ft_null_array.c ft_sign.c
PRINTF_FILES = ft_printf_utils.c ft_printf.c writes.c writes_2.c
FPRINTF_FILES = ft_fprintf_utils.c ft_fprintf.c fwrites.c fwrites_2.c
GNL_FILES = get_next_line.c get_next_line_utils.c \


SOURCES = $(addprefix $(SOURCES_DIR), $(FILES))
PRINTF_SOURCES = $(addprefix $(PRINTF_DIR), $(PRINTF_FILES))
FPRINTF_SOURCES = $(addprefix $(FPRINTF_DIR), $(FPRINTF_FILES))
GNL_SOURCES = $(addprefix $(GNL_DIR), $(GNL_FILES))

OBJECTS = $(addprefix $(OBJECTS_DIR), $(FILES:.c=.o))
PRINTF_OBJECTS = $(PRINTF_SOURCES:.c=.o)
FPRINTF_OBJECTS = $(FPRINTF_SOURCES:.c=.o)
GNL_OBJECTS = $(GNL_SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g
CC = gcc
NAME = libft.a

all: $(OBJECTS_DIR) $(NAME)

$(NAME): $(OBJECTS) $(PRINTF_OBJECTS) $(GNL_OBJECTS) $(FPRINTF_OBJECTS)
	@echo "compiling: $(YELLOW)creating library$(DEFAULT)"
	@ar -rcsu $@ $^
	@echo "$(GREEN)$@ successfully compiled!$(DEFAULT)"

$(OBJECTS_DIR):
	@echo "$(YELLOW)creating $@ folder$(DEFAULT)"
	@mkdir objects

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	@echo "compiling: $(YELLOW)$@$(DEFAULT)"
	@$(CC) -c $(CFLAGS) -o $@ $^

$(PRINTF_DIR)%.o: $(PRINTF_DIR)%.c
	@echo "compiling: $(YELLOW)$@$(DEFAULT)"
	@$(CC) -c $(CFLAGS) -o $@ $^

$(FPRINTF_DIR)%.o: $(FPRINTF_DIR)%.c
	@echo "compiling: $(YELLOW)$@$(DEFAULT)"
	@$(CC) -c $(CFLAGS) -o $@ $^

$(GNL_DIR)%.o: $(GNL_DIR)%.c
	@echo "compiling: $(YELLOW)$@$(DEFAULT)"
	@$(CC) -c $(CFLAGS) -o $@ $^

rmlib:
	@echo "cleaning:  $(RED)removing $(NAME)$(DEFAULT)"
	@rm -f $(NAME)

clean:
	@echo "cleaning:  $(RED)removing object files$(DEFAULT)"
	@rm -f $(OBJECTS) $(GNL_OBJECTS) $(PRINTF_OBJECTS) $(FPRINTF_OBJECTS)

fclean: clean rmlib

re: fclean all

.PHONY: all clean fclean re bonus
