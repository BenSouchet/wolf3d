# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 15:48:09 by bsouchet          #+#    #+#              #
#    Updated: 2016/09/28 19:07:51 by bsouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -O3

DIR_S = sources

DIR_O = temporary

HEADER = include

SOURCES = ft_itoa.c \
		  ft_checkstr.c \
		  ft_del_dir_name.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_strchr.c \
		  ft_strchr_at_end.c \
		  ft_strdup.c \
		  ft_strjoin.c \
		  ft_strlen.c \
		  ft_color.c \
		  get_next_line.c


SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: temporary $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

temporary:
	@mkdir -p temporary

$(DIR_O)/%.o: $(DIR_S)/%.c
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette ../libft/$(HEADER)
	@echo
	norminette ../libft/$(DIR_S)

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all
