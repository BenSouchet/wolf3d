# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/24 14:18:13 by bsouchet          #+#    #+#              #
#    Updated: 2016/04/12 16:58:29 by bsouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libmlx.a

FLAGS = -O3 -msse4

DIR_S = sources

DIR_OC = temporary_c

DIR_OM = temporary_m

HEADERS = includes

SOURCES_C = mlx_shaders.c \
			mlx_xpm.c \
			mlx_int_str_to_wordtab.c

SOURCES_M = mlx_new_window.m \
			mlx_init_loop.m \
			mlx_new_image.m

SRCS_C = $(addprefix $(DIR_S)/,$(SOURCES_C))

SRCS_M = $(addprefix $(DIR_S)/,$(SOURCES_M))

OBJS_C = $(addprefix $(DIR_OC)/,$(SOURCES_C:.c=.o))

OBJS_M = $(addprefix $(DIR_OM)/,$(SOURCES_M:.m=.o))

all: temporary $(NAME)

$(NAME): $(OBJS_C) $(OBJS_M)
	@ar rc $(NAME) $(OBJS_C) $(OBJS_M)
	@ranlib $(NAME)

temporary:
	@mkdir -p temporary_c
	@mkdir -p temporary_m

$(DIR_OC)/%.o: $(DIR_S)/%.c
	@$(CC) $(FLAGS) -I $(HEADERS) -o $@ -c $<

$(DIR_OM)/%.o: $(DIR_S)/%.m
	@$(CC) $(FLAGS) -I $(HEADERS) -o $@ -c $<

clean:
	@rm -f $(OBJS_C) $(OBJS_M)
	@rm -rf $(DIR_OC) $(DIR_OM)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, temporary, clean, fclean, re
