# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 11:00:53 by rshatra           #+#    #+#              #
#    Updated: 2024/04/07 22:21:00 by rshatra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTDIR = ./libft
LIBFTNAME = libft.a
CFLAGS = -Wall -Werror -Wextra
CC = cc

# object files to be created from the source
SRCS = ft_printf.c sub_libft.c format_print.c sub_libft2.c

OBJ = $(SRCS:.c=.o)

# build the target $(NAME) and $(OBJ)
all: $(NAME) $(OBJ)

# building the libft library.
# runs make command in the $(LIBFTDIR) directory, which builds the libft library.
# copies the libft.a file from LIBFTDIR to the current directory.
# renames libft.a to libftprintf.a
# -C is used to specify the directory in which make should operate
makelibft:
		@make -C $(LIBFTDIR)
		@cp $(LIBFTDIR)/$(LIBFTNAME) .
		@mv $(LIBFTNAME) $(NAME)

# build the makelibft target and then build the object files.
# creates the library $(NAME) from the object files $(OBJ) using the ar (archiver) command.
# updates the archive index to speed up access to the archive's contents using the ranlib command.
$(NAME): makelibft $(OBJ)
		@ar -r $(NAME) $(OBJ)
		@ranlib $(NAME)

clean:
	@rm -f $(OBJ)
	@cd $(LIBFTDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean

re: fclean all
