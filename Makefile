# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-bekk <<ael-bekk@student.1337.ma>>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 09:09:28 by ael-bekk          #+#    #+#              #
#    Updated: 2022/02/14 19:13:41 by ael-bekk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
BONUS		= lib_bonus.a
MANDAT		= lib_man.a
obj			= obj
CFLAGS 		= -Wextra -Wall -Werror
CC 			= cc
RM			= rm -rf
AR			= ar -rcs

SRC_COMM 	= srcs/parcing.c srcs/pipx.c srcs/errors.c \
				inc/ft_join_paths.c inc/ft_split.c inc/ft_strlen.c inc/ft_strnstr.c inc/get_next_line.c inc/get_next_line_utils.c inc/ft_calloc.c inc/ft_strlcat.c
SRCS_MAN 	= files/main.c 
SRCS_BNS 	= files/main_bonus.c 


OBJ_COMM	= $(SRC_COMM:.c=.o)
OBJ_MAN		= $(SRCS_MAN:.c=.o)
OBJ_BNS		= $(SRCS_BNS:.c=.o)

all : $(NAME)

$(NAME) : $(MANDAT)
	@$(CC) $(CFLAGS) $(MANDAT) -o $(NAME)

$(MANDAT) : $(OBJ_MAN) $(OBJ_COMM)
	@$(RM) $(BONUS)
	@$(AR) $(MANDAT) $(OBJ_MAN) $(OBJ_COMM)

bonus :	$(BONUS)

$(BONUS) : $(OBJ_BNS) $(OBJ_COMM)
	@$(RM) $(MANDAT)
	@$(AR) $(BONUS) $(OBJ_BNS) $(OBJ_COMM)
	@$(CC) $(CFLAGS) $(BONUS) -o $(NAME)

clean : 
	@$(RM) $(MANDAT) $(BONUS) $(OBJ_BNS) $(OBJ_COMM) $(OBJ_MAN)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean